#include <stdio.h>
#include <stdlib.h>
struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
};

// Insert at start (after dummy head)
struct Node* insert_start(struct Node *head,int val){
    struct Node *newNode = (struct Node *)(malloc(sizeof(struct Node)));

    newNode->data = val;
    newNode->prev = head;
    newNode->next = head->next;

    if(head->next != NULL){   
        head->next->prev = newNode;
    }

    head->next = newNode;
    return head;
}

struct Node* insertEnd(struct Node* head,int val){
    struct Node *temp = head;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = NULL;
    newNode->data = val;
    return head;
}

struct Node* insertPos(struct Node* head,int val,int pos){
    struct Node *temp = head;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    int i = 0;

    while(temp->next != NULL && i < pos-1){
        temp = temp->next;
        i++;
    }

    newNode->data = val;
    newNode->next = temp->next;     
    newNode->prev = temp;

    if(temp->next != NULL){         
        temp->next->prev = newNode;
    }

    temp->next = newNode;
    return head;
}

struct Node* delEnd(struct Node* head){
    if(head->next == NULL) return head; // empty list

    struct Node *temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
    return head;
}

struct Node* delPos(struct Node* head,int pos){
    struct Node* temp = head->next;
    int i = 0;

    if(temp == NULL) return head;

    while(temp != NULL && i < pos){
        temp = temp->next;
        i++;
    }

    if(temp == NULL) return head;

    temp->prev->next = temp->next;
    if(temp->next != NULL){          
        temp->next->prev = temp->prev;
    }

    free(temp);
    return head;
}

void printList(struct Node* head){
    struct Node *temp = head->next;  // skip dummy head
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

void freeList(struct Node *head){
    struct Node *temp = head;
    while(temp != NULL){
        struct Node *next = temp->next;
        free(temp);
        temp = next;
    }
}

int main(){
    struct Node *head = NULL;
    int choice,val,pos;

    head = (struct Node *)malloc(sizeof(struct Node));
    head->prev = NULL;
    head->next = NULL;
    head->data = 0;   // dummy head

    int n;
    printf("Enter n: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        int val;
        scanf("%d",&val);
        head = insertEnd(head,val);  
    }

    do{
        printf("\n----- MENU -----\n");
        printf("1. Insert Start\n");
        printf("2. Insert End\n");
        printf("3. Delete End\n");
        printf("4. Insert Position\n");
        printf("5. Delete Position\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter value: ");
                scanf("%d",&val);
                head = insert_start(head,val);
                printList(head);
                printf("\n");
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d",&val);
                head = insertEnd(head,val);
                printList(head);
                printf("\n");
                break;

            case 3:
                head = delEnd(head);
                printList(head);
                printf("\n");
                break;

            case 4:
                printf("Enter value and position: ");
                scanf("%d %d",&val,&pos);
                head = insertPos(head,val,pos);
                printList(head);
                printf("\n");
                break;

            case 5:
                printf("Enter position: ");
                scanf("%d",&pos);
                head = delPos(head,pos);
                printList(head);
                printf("\n");
                break;

            case 0:
                break;

            default:
                printf("Invalid choice\n");
        }

    }while(choice!=0);

    freeList(head);
    return 0;
}
