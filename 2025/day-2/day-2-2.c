#include <math.h>
#include <stdio.h>

int is_repeating(long n);

long lb, ub;
char c;
long res = 0;

int main() {
    long i;
    while (scanf("%ld-%ld%c", &lb, &ub, &c) >= 2) {
        for (i = lb; i <= ub; i++) {
            if (is_repeating(i)) {
                res += i;
            }
        }
        if (c == '\n' || c == EOF)
            break;
    }
    printf("Res: %ld", res);
    return 0;
}

int is_repeating(long n) {
    int len = floor(log10(n)) + 1;
    long divisor, pattern, tmp;
    int pattern_len, j, match;
    for (pattern_len = 1; pattern_len <= len / 2; pattern_len++) {
        if (len % pattern_len != 0)
            continue;

        divisor = 1;
        for (j = 0; j < pattern_len; j++)
            divisor *= 10;

        pattern = n % divisor;
        tmp = n;
        match = 1;

        while (tmp > 0) {
            if (tmp % divisor != pattern) {
                match = 0;
                break;
            }
            tmp /= divisor;
        }

        if (match)
            return 1;
    }
    return 0;
}
