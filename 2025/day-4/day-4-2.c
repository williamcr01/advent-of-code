#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define SIZE 139
char grid[SIZE][SIZE];

int check_access(int max_adjacent);

int main() {
    memset(grid, '.', sizeof(grid));

    int count_col = 1;
    int count_row = 1;
    char temp;

    while (scanf("%c", &temp) == 1) {
        if (temp == '\n') {
            count_col = 1;
            count_row++;
            continue;
        }
        grid[count_row][count_col] = temp;
        count_col++;
    }
    int accessible = check_access(4);
    printf("%d\n", accessible);
    return 0;
}

int check_access(int max_adjacent) {
    int neighbor_count;
    int count_loop;
    int count = 0;
    bool finding = true;
    while (finding) {
        count_loop = 0;
        for (int row = 1; row < SIZE - 1; row++) {
            for (int col = 1; col < SIZE - 1; col++) {
                if (grid[row][col] == '@') {
                    neighbor_count = 0;
                    if (grid[row - 1][col - 1] == '@') {
                        neighbor_count++;
                    }
                    if (grid[row - 1][col] == '@') {
                        neighbor_count++;
                    }
                    if (grid[row - 1][col + 1] == '@') {
                        neighbor_count++;
                    }
                    if (grid[row][col - 1] == '@') {
                        neighbor_count++;
                    }
                    if (grid[row][col + 1] == '@') {
                        neighbor_count++;
                    }
                    if (grid[row + 1][col - 1] == '@') {
                        neighbor_count++;
                    }
                    if (grid[row + 1][col] == '@') {
                        neighbor_count++;
                    }
                    if (grid[row + 1][col + 1] == '@') {
                        neighbor_count++;
                    }
                    if (neighbor_count < max_adjacent) {
                        grid[row][col] = '.';
                        count++;
                        count_loop++;
                    }
                } else {
                    continue;
                }
            }
        }
        if (count_loop == 0) {
            finding = false;
        }
    }
    return count;
}
