#include <stdio.h>
int sumf(int arr[],int sum,int index,int size){
    if(index == size/sizeof(arr[0])-1){
        return sum+arr[index];
    }
    sumf(arr,sum+arr[index],index+1,size);


}

int main(){
    int arr[]={1,2,3,4};
    int sum=0;
    int size= sizeof(arr);
    printf("%d",sumf(arr,sum,0,size));
}