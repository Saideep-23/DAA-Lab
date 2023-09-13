#include <stdio.h>

int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i; // Element found, return its index
        }
    }
    return -1; // Element not found
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n],target;

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) 
        scanf("%d", &arr[i]);
    printf("Enter search element : ");
    scanf("%d",&target);
    int result = linearSearch(arr, n, target);

    if (result != -1) {
        printf("Element found at position: %d\n", result+1);
    } else {
        printf("Element not found in the array\n");
    }

    return 0;
}

