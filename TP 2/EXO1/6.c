#include<stdio.h>
#include<stdlib.h>

int existe (int T[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (T[i] == x) {
            return 1;
        }
    }
    return 0;
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
    int x;
    printf("Enter the element to search for: ");
    scanf("%d", &x);
    int found = existe(arr, n, x);
    if (found) {
        printf("The element %d exists in the array.\n", x);
    } else {
        printf("The element %d does not exist in the array.\n", x);
    }
    return 0;
}