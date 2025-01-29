#include<stdio.h>

void printarr(int *A, int n) {
    for (size_t i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void selectionsort(int *A, int n) {
    int min;
    printf("Running selection sort....\n");
    for (size_t i = 0; i < n - 1; i++) {
        min = i;
        for (size_t j = i + 1; j < n; j++) {
            if (A[j] < A[min]) {
                min = j;
            }
        }
        int temp = A[i];
        A[i] = A[min];
        A[min] = temp;
    }
}

int main(void) {
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int A[n]; 
    printf("Enter %d elements of the array:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }



    selectionsort(A, n);

    printarr(A, n);

    return 0;
}
