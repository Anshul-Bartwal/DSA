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

int main(){
    printf("Hello\n");
    int n;
    printf("How many nodes? ");
    scanf("%d", &n);

    struct Node *head = create(n);

    printf("Your Linked List:\n");
    printList(head);

    freeList(head);
    return 0;




    


}