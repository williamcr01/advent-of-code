#include <math.h>
#include <stdio.h>
#include <string.h>

int main() {
    char line[1024];
    int i, len, k, end;
    int largest[12] = {0};
    int largest_i[12] = {0};
    long res = 0;

    while (fgets(line, sizeof(line), stdin)) {
        len = strlen(line);
        if (line[len - 1] == '\n')
            len--;

        int digits[len];
        for (i = 0; i < len; i++) {
            digits[i] = line[i] - '0';
            if (digits[i] > largest[0] && i < len - 11) {
                largest[0] = digits[i];
                largest_i[0] = i;
            }
        }
        res += largest[0] * (long)pow(10, 11);
        for (k = 1; k < 12; k++) {
            end = len - (11 - k);
            for (i = largest_i[k - 1] + 1; i < end; i++) {
                if (digits[i] > largest[k]) {
                    largest[k] = digits[i];
                    largest_i[k] = i;
                }
            }
            res += largest[k] * (long)pow(10, 11 - k);
        }

        for (i = 0; i < 12; i++) {
            largest[i] = 0;
            largest_i[i] = 0;
        }
    }
    printf("Res: %ld", res);
    return 0;
}
