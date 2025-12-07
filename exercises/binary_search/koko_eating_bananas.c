#include <stdio.h>

long long hours_needed(int *piles, int n, int k) {
    long long hours = 0;
    for (int i = 0; i < n; i++) {
        hours += (piles[i] + k - 1) / k;
    }
    return hours;
}

int min_eating_speed(int *piles, int n, int h) {
    int left = 1, right = 1;
    for (int i = 0; i < n; i++) {
        if (piles[i] > right) right = piles[i];
    }

    int ans = right;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        long long needed = hours_needed(piles, n, mid);
        if (needed <= h) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n, h;
    printf("Enter number of piles: ");
    scanf("%d", &n);
    if (n <= 0) return 0;

    int piles[1000];
    if (n > 1000) n = 1000;
    printf("Enter %d pile sizes: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &piles[i]);

    printf("Enter hours h: ");
    scanf("%d", &h);

    int k = min_eating_speed(piles, n, h);
    printf("Minimum eating speed: %d\n", k);
    return 0;
}
