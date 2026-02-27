#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
};

struct Node* create(int n){
    struct Node *temp = NULL;
    struct Node *newNode=NULL;
    struct Node *head = NULL;
    for (int i=0;i<n;i++){
        newNode=(struct Node *)(malloc(sizeof(struct Node)));
        newNode->next=NULL;
        printf("Enter data for node: %d:",i+1);
        scanf("%d",&newNode->data);

        if(head == NULL){
            head = newNode;
            temp = newNode;
        }else{
            temp->next = newNode;
            temp=newNode;
        }
    }
    return head;

    
    
}

void printList(struct Node *head){
    struct Node *temp = head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }

}

void freeList(struct Node *head) {
    struct Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

struct Node* insert_start(int val,struct Node *head){

    struct Node *newNode=NULL;
    newNode=(struct Node *)(malloc(sizeof(struct Node)));
    

    newNode->data=val;
    newNode->next=head;
    return newNode;
    

}

void insert_end(int val,struct Node *head){

    struct Node *temp=head;
    struct Node *newNode=NULL;
    newNode=(struct Node *)(malloc(sizeof(struct Node)));
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->data=val;
    newNode->next=NULL;

}

struct Node* insert_pos(int val,struct Node *head,int pos){
    struct Node *temp=head;
    if(pos==1){
        return insert_start(val,head);
    }
    for(int i=0;i<pos-1 && temp!=NULL;i++){
        temp=temp->next;
    }
    struct Node *newNode=NULL;
    newNode=(struct Node *)(malloc(sizeof(struct Node)));
    newNode->data=val;
    newNode->next=temp->next;
    temp->next=newNode;

    return newNode;


}

struct Node* delStart(struct Node *head){
    if(head==NULL){
        return NULL;
    }
    struct Node *temp=head->next;
    free(head);
    return temp;
}

void delEnd(struct Node* head){
    if(head==NULL){
        return ;
    }
    struct Node *temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
}


struct Node* delPos(struct Node* head,int pos){
    if(pos==1){
        return delStart(head);
    }
    struct Node *temp=head;
    for(int i=1;i<pos-1&& temp!=NULL;i++){
        temp=temp->next;


    }
    if(temp == NULL || temp->next == NULL){
        return head;
    }
    
    struct Node *nodeToDelete = temp->next;
  
    temp->next = temp->next->next;
    
    free(nodeToDelete);
    return head;
}

int main(){
    int n, choice, val, pos;
    struct Node *head = NULL;

    printf("How many nodes? ");
    scanf("%d", &n);
    head = create(n);

    do{
        printf("\n----- MENU -----\n");
        printf("1. Insert Start\n");
        printf("2. Insert End\n");
        printf("3. Delete Start\n");
        printf("4. Delete End\n");
        printf("5. Insert at Position\n");
        printf("6. Delete at Position\n");
        ;
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter value: ");
                scanf("%d",&val);
                head = insert_start(val, head);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d",&val);
                insert_end(val, head);
                break;

            case 3:
                head = delStart(head);
                break;

            case 4:
                delEnd(head);
                break;

            case 5:
                printf("Enter value and position: ");
                scanf("%d %d",&val,&pos);
                head = insert_pos(val, head, pos);
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d",&pos);
                head = delPos(head, pos);
                break;

            case 0:
                break;

            default:
                printf("Invalid choice!\n");
        }
        printf("Your Linked List:\n");
        printList(head);

    }while(choice != 0);

    freeList(head);
    return 0;
}
// int main(){
//     printf("Hello\n");
//     int n;
//     int choice;
//     int more;
//     do{
//         printf("1. Insert Start\n" );
//         printf("2. Insert End\n" );
//         printf("3. Delete Start\n" );
//         printf("4. Delete End\n" );
//         printf("5. Insert Pos\n" );
//         printf("6. Delete pos\n" );
//         printf("What you want to do:");
//         scanf("%d",&choice);
//     }while(more);
//     printf("How many nodes? ");
//     scanf("%d", &n);

//     struct Node *head = create(n);



//     printf("Your Linked List:\n");
//     printList(head);

//     printf("h1");
//     insert_end(10,head);
//     printf("h1");
//     head=insert_start(10,head);
//     head=insert_start(10,head);
//     insert_end(10,head);

//     delEnd(head);
//     head=delStart(head);
//     printf("Your Linked List:\n");
//     printList(head);
//     head=insert_pos(100,head,1);

//     head=delPos(head,3);
//     printf("Your Linked List:\n");
//     printList(head);
//     freeList(head);
//     return 0;
// }
