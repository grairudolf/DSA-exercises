#include <stdio.h>

int two_sum(int *nums, int n, int target, int *i_out, int *j_out) {
    int i = 0;
    int j = n - 1;

    // Simple selection-sort-like pass to sort while tracking original indices is
    // overkill here; for learning purposes we just do O(n^2) search.
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                *i_out = i;
                *j_out = j;
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int n, target;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 1) {
        printf("Need at least two numbers.\n");
        return 0;
    }

    int nums[1000];
    if (n > 1000) n = 1000;

    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    printf("Enter target sum: ");
    scanf("%d", &target);

    int i_idx, j_idx;
    if (two_sum(nums, n, target, &i_idx, &j_idx)) {
        printf("Found indices %d and %d (values %d + %d = %d)\n",
               i_idx, j_idx, nums[i_idx], nums[j_idx], target);
    } else {
        printf("No two numbers sum to %d.\n", target);
    }

    return 0;
}
