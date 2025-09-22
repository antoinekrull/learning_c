#include <stdio.h>

int main() {
    int arr[] = {5, 1, 4, 2, 8, 17, 4, 12, 6};

    int i, j;
    int length = sizeof(arr) / sizeof(arr[0]);
    for (i = length; i > 1; i--) {
        for (j = 0; j < i - 1; j = j + 1) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < length; i++) {
        printf("%d", arr[i]);
        printf("\n");
    }
    return 0;
}