#include <stdio.h>
#define MAX 10
int stack[10];
int top=-1;
void push(int *stack,int x){
    if(top== MAX-1){
        printf("Stack Overflow\n");
        return;
    }
    stack[++top]=x;
}

void pop(int *stack) {
    if (top==-1) {
        printf("Stack Underflow\n");
        return;
    }
    printf("Deleted element: %d\n", stack[top--]);
}

void display(int *stack) {
    printf("stack: ");
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    push(stack,10);
    push(stack,20);
    push(stack,30);
    display(stack);
    pop(stack);
    display(stack);
    return 0;
}