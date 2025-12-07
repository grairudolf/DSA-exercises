#include <stdio.h>

void swap_int(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

int partition(int *arr, int *freq, int left, int right) {
    int pivot = freq[right];
    int i = left;
    for (int j = left; j < right; j++) {
        if (freq[j] > pivot) {
            swap_int(&freq[i], &freq[j]);
            swap_int(&arr[i], &arr[j]);
            i++;
        }
    }
    swap_int(&freq[i], &freq[right]);
    swap_int(&arr[i], &arr[right]);
    return i;
}

void quickselect(int *arr, int *freq, int left, int right, int k) {
    if (left >= right) return;
    int pivotIndex = partition(arr, freq, left, right);
    int count = pivotIndex - left + 1;
    if (k < count) quickselect(arr, freq, left, pivotIndex - 1, k);
    else if (k > count) quickselect(arr, freq, pivotIndex + 1, right, k - count);
}

int top_k_frequent(int *nums, int n, int k, int *out) {
    if (n <= 0 || k <= 0) return 0;

    int values[1000];
    int freq[1000];
    int unique = 0;

    for (int i = 0; i < n; i++) {
        int v = nums[i];
        int found = 0;
        for (int j = 0; j < unique; j++) {
            if (values[j] == v) {
                freq[j]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            values[unique] = v;
            freq[unique] = 1;
            unique++;
        }
    }

    if (k > unique) k = unique;

    quickselect(values, freq, 0, unique - 1, k);

    for (int i = 0; i < k; i++) {
        out[i] = values[i];
    }
    return k;
}

int main() {
    int n, k;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if (n <= 0 || n > 1000) return 0;

    int nums[1000];
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);

    printf("Enter k: ");
    scanf("%d", &k);

    int out[1000];
    int count = top_k_frequent(nums, n, k, out);
    printf("Top %d frequent elements (unordered): ", count);
    for (int i = 0; i < count; i++) printf("%d ", out[i]);
    printf("\n");
    return 0;
}
