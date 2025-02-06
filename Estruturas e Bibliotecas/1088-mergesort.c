#include <stdio.h>
#include <stdlib.h>

#define MAX 112345

int ans;

void merge(int arr[], int start, int mid, int end) {
    int *aux_arr = malloc(end - start + 1 * sizeof(int));
    int i = start;
    int j = mid + 1;
    int k = 0;
    while(i <= mid && j <= end) {
        if(arr[i] <= arr[j]) {
            aux_arr[k] = arr[i];
            i++;
        } else {
            aux_arr[k] = arr[j];
            ans += mid - i + 1;
            j++;
        }
        k++;
    }
    while(i <= mid) {
        aux_arr[k] = arr[i];
        k++; i++;
    }
    while(j <= end) {
        aux_arr[k] = arr[j];
        k++; j++;
    }
    for(k = start; k <= end; k++) {
        arr[k] = aux_arr[k - start];
    }
    free(aux_arr);
}

void merge_sort(int arr[], int start, int end) {
    if(start < end) {
        int mid = (start + end) / 2;
        merge_sort(arr, start, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

int main() {
    int n, arr[MAX];
    while(scanf("%d", &n), n) {
        for(int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        ans = 0;
        merge_sort(arr, 0, n - 1);
        printf("%s\n", ans & 1 ? "Marcelo" : "Carlos");
    }
}
