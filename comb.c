#include <stdio.h>

void comb_sort(int arr[], int len) {
    double shrink_factor = 0.8;
    int gap = len, swapped = 1, i;
    int temp;
    while (gap > 1 || swapped) {
        if (gap > 1) {
            gap *= shrink_factor;
        }
        swapped = 0;
        for (i = 0; gap + i < len; i++) {
            if (arr[i] > arr[i + gap]) {
                temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
                swapped = 1;
            }
        }
    }
}

int main() {
    int arr[] = {22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70};

    int len = (int) sizeof(arr) / sizeof(*arr);

    comb_sort(arr, len);
    int i;
    for(i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
