#include <stdio.h>
int main(){
    int r,c;
    printf("Enter r and c");
    scanf("%d %d",&r,&c);
    int arr[r][c];
    printf("Enter elements row wise: \n");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&arr[i][j]);
        }
    }

    int sumArr[r];
    for(int i=0;i<r;i++){
        sumArr[i]=0;
    }
    int *base=&arr[0][0];
    int index=0;    
    for(int i=0;i<r*c;i++){
        int row=i/c;
        sumArr[row]+=*(base+i);
    }

    printf("\nRow sums:\n");
    for(int i = 0; i < r; i++) {
        printf("Row %d sum = %d\n", i, sumArr[i]);
    }

    return 0;

}