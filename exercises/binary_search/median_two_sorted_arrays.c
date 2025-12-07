#include <stdio.h>

// Simpler O(m+n) merge-based median for learning purposes.
double find_median_two_sorted(int *a, int m, int *b, int n) {
    int total = m + n;
    int mid1 = (total - 1) / 2;
    int mid2 = total / 2;

    int i = 0, j = 0, k = 0;
    int cur = 0, prev = 0;

    while (k <= mid2 && (i < m || j < n)) {
        prev = cur;
        if (j >= n || (i < m && a[i] <= b[j])) {
            cur = a[i++];
        } else {
            cur = b[j++];
        }
        if (k == mid1) prev = cur;
        k++;
    }

    if (total % 2 == 1) return cur;
    return (prev + cur) / 2.0;
}

int main() {
    int m, n;
    printf("Enter size of first array: ");
    scanf("%d", &m);
    printf("Enter size of second array: ");
    scanf("%d", &n);

    int a[1000], b[1000];
    if (m > 1000) m = 1000;
    if (n > 1000) n = 1000;

    printf("Enter %d sorted integers for first array: ", m);
    for (int i = 0; i < m; i++) scanf("%d", &a[i]);

    printf("Enter %d sorted integers for second array: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);

    double med = find_median_two_sorted(a, m, b, n);
    printf("Median: %.2f\n", med);
    return 0;
}
