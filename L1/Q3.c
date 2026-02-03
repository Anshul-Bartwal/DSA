#include <stdio.h>
int main(){
    int arr[]={1,21,13,84,0};
    int min=arr[0];
    int max=arr[0];
    for (int i=1;i<5;i++){
        if(arr[i] > max ){
            max = arr[i];
            continue;
        }
        if (arr[i] < min ){
            min = arr[i];
            continue;
        }
    }
    printf("Max: %d\nMin: %d",max,min);
    return 0;
}