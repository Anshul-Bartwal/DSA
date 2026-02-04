#include <stdio.h>
int main(){
    int arr1[2][3] = { {1, 2, 3}, {4, 5, 6} };

    int arr2[3][2] = { {1,2} ,{ 3,4}, {5,6}};
    int *a =&arr1[0][0];
    int *b =&arr2[0][0];
    int arr[2][2] ={0};
    int *c = &arr[0][0];
    int k=0;
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            arr[i][k++] += arr1[i][j] + arr2[j][i];
        }
        k=0;
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    return 0;

}