#include <stdio.h>

int max_profit(int *prices, int n) {
    if (n <= 1) return 0;

    int min_price = prices[0];
    int max_prof = 0;

    for (int i = 1; i < n; i++) {
        if (prices[i] < min_price) {
            min_price = prices[i];
        } else {
            int profit = prices[i] - min_price;
            if (profit > max_prof) {
                max_prof = profit;
            }
        }
    }
    return max_prof;
}

int main() {
    int n;
    printf("Enter number of days: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Number of days must be positive.\n");
        return 0;
    }

    int prices[1000];
    if (n > 1000) n = 1000;

    printf("Enter %d stock prices: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &prices[i]);
    }

    int result = max_profit(prices, n);
    printf("Maximum profit: %d\n", result);

    return 0;
}
