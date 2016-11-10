#include <stdio.h>

typedef struct _Range {
    int start, end;
} Range;
Range new_Range(int s, int e) {
    Range r;
    r.start = s;
    r.end = e;
    return r;
}
void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}
void quick_sort(int arr[], const int len) {
    if (len <= 0) {
        return;
    }
    Range r[len];
    int p = 0;
    r[p++] = new_Range(0, len - 1);
    while(p) {
        Range range = r[--p];
        if (range.start >= range.end) {
            continue;
        }
        int mid = arr[range.end];
        int left = range.start, right = range.end - 1;
        while (left < right) {
            while (arr[left] < mid && left < right) {
                left++;
            }
            while (arr[right] >= mid && left < right) {
                right--;
            }
            swap(&arr[left], &arr[right]);
        }
        if (arr[left] >= arr[range.end]) {
            swap(&arr[left], &arr[range.end]);
        }else {
            left++;
        }
        r[p++] = new_Range(range.start, left - 1);
        r[p++] = new_Range(left + 1, range.end);
    }
}

int main() {
    int arr[] = {22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70};

    int len = (int) sizeof(arr) / sizeof(*arr);

    quick_sort(arr, len);
    int i;
    for(i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
