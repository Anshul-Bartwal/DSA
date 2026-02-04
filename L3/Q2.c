#include <stdio.h>
#include <stdlib.h>
int main(){
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    int *arr = (int *)calloc(n,sizeof(int));
    printf("Enter array elements: ");
    for(int k=0;k<n;k++){
        scanf("%d",&arr[k]);
    }
    int i,val;
    printf("Enter i and value");
    scanf("%d",&i);
    scanf("%d",&val);
    int *temp = realloc(arr,(n+1)*sizeof(int));
    arr=temp;
    for(int k=n-1;k>=i;k--){
        arr[k+1]=arr[k];
    }
    n++;
    arr[i] = val;

    int j;
    printf("Enter j");
    scanf("%d",&j);

    for(int k=j;k<n-1;k++){
        arr[k] = arr[k+1];
    }
    arr[n-1] = 0;
    for(int k=0;k<n-1;k++){
        printf("%d",arr[k]);
    }
    free(arr);
    return 0;
    

}