#include<stdio.h>
#include<stdlib.h>

int longueS (int T[], int n) {
    int count = 1;
    int max = 1;

    if (n <= 0) {
        return 0;
    }
    for (int i = 1; i < n; i++) {
        if (T[i] == T[i - 1]) {
            count++;
        }
        else {
            if (count > max) {
            max = count;
            }
            count = 1;
        }
    }
    if (count > max) {
        max = count;
    }
    return max;
}
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    int max = longueS(arr, n);
    printf("The maximum number of longurrences of any element in the array is %d.\n", max);
    return 0;
}