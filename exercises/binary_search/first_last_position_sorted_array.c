#include <stdio.h>

int find_first(int *nums, int n, int target) {
    int left = 0, right = n - 1, ans = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] >= target) {
            if (nums[mid] == target) ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

int find_last(int *nums, int n, int target) {
    int left = 0, right = n - 1, ans = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] <= target) {
            if (nums[mid] == target) ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

int main() {
    int n, target;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if (n <= 0) return 0;

    int nums[1000];
    if (n > 1000) n = 1000;
    printf("Enter %d sorted integers: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);

    printf("Enter target: ");
    scanf("%d", &target);

    int first = find_first(nums, n, target);
    int last = find_last(nums, n, target);
    printf("First: %d Last: %d\n", first, last);
    return 0;
}
