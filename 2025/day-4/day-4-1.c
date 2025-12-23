#include <stdio.h>

char grid[137][137];

int main() {
    int count_col = 0;
    int count_row = 0;
    char temp;
    while (scanf("%c", &temp) == 1) {
        if (temp == '\n') {
            count_col = 0;
            count_row++;
            continue;
        }
        grid[count_row][count_col] = temp;
        count_col++;
    }
    for (int i = 0; i < 137; i++) {
        for (int j = 0; j < 137; j++) {
            printf("%c", grid[i][j]);
            if (j == 136) {
                printf("\n");
            }
        }
    }
    return 0;
}
