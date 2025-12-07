#include <stdio.h>

int length_of_LIS(int *nums, int n) {
    if (n <= 0) return 0;
    int dp[1000];
    int max_len = 1;

    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
        if (dp[i] > max_len) max_len = dp[i];
    }
    return max_len;
}

int main() {
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);
    if (n <= 0) return 0;
    if (n > 1000) n = 1000;

    int nums[1000];
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);

    int res = length_of_LIS(nums, n);
    printf("Length of LIS: %d\n", res);
    return 0;
}
