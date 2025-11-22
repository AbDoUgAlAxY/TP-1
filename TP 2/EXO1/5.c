#include <stdio.h>
#include <stdlib.h>

int test ( int T[], int n ) {
    for ( int i = 0; i < n; i++){
        if (T[i] > T[i+1])
        {
             return 1;
        }
    }
    return 0;
}

int main() {
    int n;
    int arr[n] ;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    double tri = test(arr, n);
    if (tri == 1) {
        printf("The array is not sorted. \n");
    } else {
        printf("The array is sorted. \n");
    }
    return 0;
}