#include <stdio.h>
#include <string.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push(char c) {
    stack[++top] = c;
}
char pop() {
    return stack[top--];
}
int main() {
    char str[100];
    printf("Enter string: ");
    scanf("%s", str);
    int n = strlen(str);
    //enter chars in stack
    for (int i = 0; i < n; i++)
        push(str[i]);

    // Pop to reverse
    for (int i = 0; i < n; i++)
        str[i] = pop();

    printf("Reversed string: %s", str);
    return 0;
}