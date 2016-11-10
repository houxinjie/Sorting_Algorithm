#include <stdio.h>
void insertion_sort(int arr[], int len) {
    int i, j, temp;
    for(i = 1; i < len; i++){
        for(j = i - 1, temp = arr[i]; j >= 0 && arr[j] > temp; j-- ){
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = temp;
    }
}

int main() {
    int arr[] = {22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70};

    int len = (int) sizeof(arr) / sizeof(*arr);

    insertion_sort(arr, len);
    int i;
    for(i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
