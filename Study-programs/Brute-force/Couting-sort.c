#include <stdio.h>

void cs(int a[], int n) {
    int i, j, c[n], t[n];
    
    for (i = 0; i < n; i++)
        c[i] = 0;
    
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[i] < a[j])
                c[j]++;
            else
                c[i]++;
        }
    }
    
    for (i = 0; i < n; i++)
        t[c[i]] = a[i];
    
    printf("Sorted array is\n");
    for (i = 0; i < n; i++)
        printf("%d ", t[i]);  // Print the sorted array 't' instead of 'a'
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) 
        scanf("%d", &arr[i]);
    
    cs(arr, n);
    
    return 0;
}

