#include <stdio.h>
#include <string.h>

int main() {
    char line[1024];
    int i, len, largest, largest_i, second_largest;
    int res = 0;

    while (fgets(line, sizeof(line), stdin)) {
        largest = second_largest = 0;
        len = strlen(line);
        if (line[len - 1] == '\n')
            len--;

        int digits[len];
        for (i = 0; i < len; i++) {
            digits[i] = line[i] - '0';
            if (digits[i] > largest && i != len - 1) {
                largest = digits[i];
                largest_i = i;
            }
        }
        for (i = largest_i + 1; i < len; i++) {
            if (digits[i] > second_largest)
                second_largest = digits[i];
        }
        res += largest * 10 + second_largest;
    }
    printf("Res: %d", res);
    return 0;
}
