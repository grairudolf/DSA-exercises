#include <stdio.h>

int coin_change(int *coins, int coinsSize, int amount) {
    const int INF = 1000000000;
    int dp[10001];

    for (int i = 0; i <= amount; i++) dp[i] = INF;
    dp[0] = 0;

    for (int i = 0; i < coinsSize; i++) {
        int c = coins[i];
        for (int a = c; a <= amount; a++) {
            if (dp[a - c] + 1 < dp[a]) {
                dp[a] = dp[a - c] + 1;
            }
        }
    }

    return dp[amount] == INF ? -1 : dp[amount];
}

int main() {
    int n, amount;
    printf("Enter number of coin types: ");
    scanf("%d", &n);
    if (n <= 0) return 0;
    if (n > 1000) n = 1000;

    int coins[1000];
    printf("Enter %d coin values: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &coins[i]);

    printf("Enter amount: ");
    scanf("%d", &amount);
    if (amount < 0 || amount > 10000) {
        printf("Amount must be between 0 and 10000.\n");
        return 0;
    }

    int res = coin_change(coins, n, amount);
    if (res == -1) printf("Cannot make amount %d with given coins.\n", amount);
    else printf("Minimum coins needed: %d\n", res);
    return 0;
}
