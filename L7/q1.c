#include <stdio.h>
#define SIZE 5
int front=0;

int rear=-1;
void enqueue(int * q,int val,int *rear){
    if(*rear==SIZE-1){
        printf("Overflow");
        return;
    }
    q[++(*rear)]=val;
    
}

int dequeue(int *q,int *front){
    return q[(*front)++];
}
void display(int *q,int front,int rear){
    while(front<=rear){
        printf("%d ",q[front++]);
    }
}
int main(){
    int n;
    printf("Enter n:");
    scanf("%d",&n);
    int q[SIZE];
    for (int i=0;i<n;i++){
        int val;
        scanf("%d",&val);
        enqueue(q,val,&rear);
    }
    
    display(q,front,rear);
    printf("Dequeued: %d\n",dequeue(q,&front));
    display(q,front,rear);
    return 0;

    

}