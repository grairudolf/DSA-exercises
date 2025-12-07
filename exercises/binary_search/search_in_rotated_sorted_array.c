#include <stdio.h>

int search_rotated(int *nums, int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;

        if (nums[left] <= nums[mid]) {
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else {
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return -1;
}

int main() {
    int n, target;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if (n <= 0) return 0;

    int nums[1000];
    if (n > 1000) n = 1000;
    printf("Enter %d sorted-rotated integers: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);

    printf("Enter target: ");
    scanf("%d", &target);

    int idx = search_rotated(nums, n, target);
    printf("Index: %d\n", idx);
    return 0;
}
