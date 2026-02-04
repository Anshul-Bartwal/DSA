#include <stdio.h>
int main(){
    int arr1[]={1,4,3,7};
    int arr2[]={2,6,5,8};
    int l1=sizeof(arr1)/sizeof(arr1[0]);
    int l2=sizeof(arr2)/sizeof(arr2[0]);
    int arr[l1+l2];
    for(int i=0;i<l1;i++)
        arr[i] = arr1[i];
    
    for(int i=0;i<l2;i++)
        arr[l1+i] = arr2[i];
    

    for(int i=0;i<l1+l2-1;i++){
        for(int j=0;j<l1+l2-i-1;j++){
            if(arr[j] > arr[j+1]){
                int temp=arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp; 
                
            }
        }
    }
    for(int i=0;i<l1+l2;i++)printf("%d ",arr[i]);
    return 0;
}