#include <stdio.h>

int maxArea(int *height, int n) {
    int left = 0;
    int right = n - 1;
    int max_area = 0;

    while (left < right) {
        int h = height[left] < height[right] ? height[left] : height[right];
        int width = right - left;
        int area = h * width;
        if (area > max_area) {
            max_area = area;
        }

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return max_area;
}

int main() {
    int n;
    printf("Enter number of lines: ");
    scanf("%d", &n);

    if (n <= 1) {
        printf("Need at least two lines.\n");
        return 0;
    }

    int height[1000];
    if (n > 1000) n = 1000;

    printf("Enter %d heights: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &height[i]);
    }

    int result = maxArea(height, n);
    printf("Maximum water area: %d\n", result);

    return 0;
}
