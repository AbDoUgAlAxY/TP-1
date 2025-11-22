#include <stdio.h>
#include <stdlib.h>

int Occ (int T[], int n, int x) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (T[i] == x ) {
            count++;
        }
        if(T[i] > x) {
            break;
        }
    }
    return count;
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
    printf("Enter the element to count occurrences of: ");
    scanf("%d", &x);
    int occurrences = Occ(arr, n, x);
    printf("The element %d occurs %d times in the array.\n", x, occurrences);
    return 0;
}