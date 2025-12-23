#include <math.h>
#include <stdio.h>

long lb, ub;
char c;
long res = 0;

int main() {
    long i;
    while (scanf("%ld-%ld%c", &lb, &ub, &c) >= 2) {
        for (i = lb; i <= ub; i++) {
            int len = floor(log10(i)) + 1;
            if (len % 2 == 0) {
                int divisor = (int)pow(10, len / 2);
                int left = i / divisor;
                int right = i % divisor;
                if (left == right)
                    res += i;
            }
        }
        if (c == '\n' || c == EOF)
            break;
    }
    printf("Res: %ld", res);
    return 0;
}
