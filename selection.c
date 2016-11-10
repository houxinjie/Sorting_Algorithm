#include <stdio.h>

void selection_sort (int arr[], int len) {
    int i, j, min, temp;
    for (i = 0; i < len - 1; i++) {
        min = i;
        for (j = i + 1; j < len; j++) {
            if (arr[min] > arr[j]) {
                min = j;
            }
        }
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}



int main() {
    int arr[] = {22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70};

    int len = (int) sizeof(arr) / sizeof(*arr);

    selection_sort(arr, len);
    int i;
    for(i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
