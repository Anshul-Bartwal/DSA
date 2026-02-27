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

struct Node* push(int val,struct Node *head){

    struct Node *newNode=NULL;
    newNode=(struct Node *)(malloc(sizeof(struct Node)));
    

    newNode->data=val;
    newNode->next=head;
    return newNode;
    

}

struct Node* pop(struct Node *head){
    if(head==NULL){
        printf("Empty :(\n");
        return NULL;
    }
    struct Node *temp=head->next;
    free(head);
    return temp;
}

int main(){
    struct Node *head = NULL;
    head=(struct Node *)(malloc(sizeof(struct Node)));
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int val;
        scanf("%d",&val);
        head=push(val,head);
        if(i==0){
            head->next=NULL;
        }
    }
    while(1){
        int choice;
        printf("1.Push\n");
        printf("2.POP\n");
        printf("Enter choice:");
        scanf("%d",&choice);
        if(choice !=1 && choice!=2){
            printf("Hello\n");
            break;
        }else if(choice==1){
            printf("Hello2\n");
            int val;
            scanf("%d",&val);
            head=push(val,head);

        }else{
            head=pop(head);
            printf("Hello3\n");
        }
        printf("Hello4\n");
        printList(head);
        
        printf("\n");



    }
    freeList(head);
    return 0;
}