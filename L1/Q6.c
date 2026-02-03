#include <stdio.h>
#include <limits.h>

int main() {
    int arr[] = {1, 6, 6, 9, 9};
    int n = 5;

    int max = INT_MIN;
    int secMax = INT_MIN;

    for(int i = 0; i < n; i++) {
        if(arr[i] > max) {
            secMax = max;
            max = arr[i];
        }
        else if(arr[i] > secMax && arr[i] < max) {
            secMax = arr[i];
        }
    }

    if(secMax == INT_MIN)
        printf("Second maximum does not exist\n");
    else
        printf("Second Max: %d\n", secMax);

    return 0;
}
