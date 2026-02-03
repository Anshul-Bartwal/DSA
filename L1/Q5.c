#include <stdio.h>
int main(){
    int arr[]={1,21,13,84,0};
    int toFind = 13;
    int index = -1;
    for (int i=1;i<5;i++){
        if (arr[i] == toFind){
            printf("Index: %d",i);
            return 0;
        }
    }
    printf("Not found");
    return 0;
}