#include <stdio.h>

int climb_stairs(int n) {
    if (n <= 2) return n;
    int a = 1, b = 2;
    for (int i = 3; i <= n; i++) {
        int c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n;
    printf("Enter number of steps: ");
    scanf("%d", &n);
    printf("Ways to climb: %d\n", climb_stairs(n));
    return 0;
}
