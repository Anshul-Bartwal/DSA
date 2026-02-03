#include <stdio.h>
int main(){
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    int arr[n];
    int sum=0;
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        sum+=arr[i];
    }
    printf("Sum: %d\n Avg: %.2f",sum,sum/(float)n);
    return 0;
}