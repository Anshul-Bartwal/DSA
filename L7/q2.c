#include <stdio.h>
#include <string.h>
#define SIZE 100
#define MAX 100
int front=0;
int rear=-1;
char stack[MAX];
int top = -1;
void push(char *stack,char c) {
    stack[++top] = c;
}
char pop(char *stack) {
    return stack[top--];
}
void enqueue(char * q,char val,int *rear){
    if(*rear==SIZE-1){
        printf("Overflow");
        return;
    }
    q[++(*rear)]=val;   
}
char dequeue(char *q,int *front){
    return q[(*front)++];
}
int main(){
    char str[50];
    scanf("%s",str);
    int n=strlen(str);
    char q[n];
    for (int i=0;i<n;i++){
        enqueue(q,str[i],&rear);
        push(stack,str[i]);
    }
    for(int i=0;i<n;i++){
        if(dequeue(q,&front)!=pop(stack)){
            printf("Not");
            return 1;
        }
    }
    printf("Palindrome");
    return 0;
}