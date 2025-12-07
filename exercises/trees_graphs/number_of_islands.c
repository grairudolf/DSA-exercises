#include <stdio.h>

void dfs(char grid[100][100], int rows, int cols, int r, int c) {
    if (r < 0 || r >= rows || c < 0 || c >= cols) return;
    if (grid[r][c] != '1') return;
    grid[r][c] = '0';
    dfs(grid, rows, cols, r + 1, c);
    dfs(grid, rows, cols, r - 1, c);
    dfs(grid, rows, cols, r, c + 1);
    dfs(grid, rows, cols, r, c - 1);
}

int num_islands(char grid[100][100], int rows, int cols) {
    int count = 0;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (grid[r][c] == '1') {
                count++;
                dfs(grid, rows, cols, r, c);
            }
        }
    }
    return count;
}

int main() {
    int rows, cols;
    printf("Enter rows and cols: ");
    scanf("%d %d", &rows, &cols);
    if (rows <= 0 || cols <= 0 || rows > 100 || cols > 100) return 0;

    char grid[100][100];
    printf("Enter grid rows as strings of 0 and 1:\n");
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            char ch;
            scanf(" %c", &ch);
            grid[r][c] = ch;
        }
    }

    int islands = num_islands(grid, rows, cols);
    printf("Number of islands: %d\n", islands);
    return 0;
}
