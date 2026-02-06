#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
int main(){
    printf("Hello\n");
    struct Node *head = NULL;
    struct Node *a = NULL;
    struct Node *b = NULL;
    struct Node *c = NULL;
    

    a= (struct Node *)(malloc(sizeof(struct Node)));
    b= (struct Node *)(malloc(sizeof(struct Node)));
    c= (struct Node *)(malloc(sizeof(struct Node)));

    head = a;
    a->data=1;
    a->next=b;

    b->data=2;
    b->next=c;

    c->data=3;
    c->next=NULL;

    struct Node *temp = head;
    while (temp->next != NULL){
        printf("%d ",temp->data);
        temp= temp->next;

    }
    // printf("%d ",temp->data);
    free(a);

    free(b);
    free(c);
    free(temp);
    return 0;




    


}