#include <stdio.h>
void cocktail_sort(int arr[], int len) {
    int i, left = 0, right = len;
    int temp;
    while(left < right) {
        for(i = left; i < right; i++) {
            if (arr[i] > arr[i + 1]) {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
        right--;
        for(i = right; i > left; i--){
            if (arr[i - 1] > arr[i]) {
                temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
            }
        }
        left++;
    }
}

int main() {
    int arr[] = {22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70};

    int len = (int) sizeof(arr) / sizeof(*arr);

    cocktail_sort(arr, len);
    int i;
    for(i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
