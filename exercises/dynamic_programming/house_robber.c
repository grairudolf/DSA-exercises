#include <stdio.h>

int house_robber(int *nums, int n) {
    if (n <= 0) return 0;
    if (n == 1) return nums[0];

    int prev2 = nums[0];
    int prev1 = nums[0] > nums[1] ? nums[0] : nums[1];

    for (int i = 2; i < n; i++) {
        int take = prev2 + nums[i];
        int skip = prev1;
        int cur = take > skip ? take : skip;
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}

int main() {
    int n;
    printf("Enter number of houses: ");
    scanf("%d", &n);
    if (n <= 0) return 0;
    if (n > 1000) n = 1000;

    int nums[1000];
    printf("Enter %d house values: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);

    int res = house_robber(nums, n);
    printf("Maximum amount that can be robbed: %d\n", res);
    return 0;
}
