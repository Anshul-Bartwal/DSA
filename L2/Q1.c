#include <stdio.h>
int main(){
    int arr[]={1,2,3,4,5,6};
    int len= sizeof(arr)/sizeof(arr[1]);
    for(int i=0;i<len/2;i++){
        arr[i] = arr[i] + arr[len-i-1];
        arr[len-i-1] =arr[i] - arr[len-i-1];
        arr[i] -= arr[len-i-1];
    }

    for(int i =0;i<len;i++){
        printf("%d",arr[i]);
    }
    return 0;
}