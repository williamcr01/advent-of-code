#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long long start;
    long long end;
} Range;

int cmp_ranges(const void *a, const void *b) {
    long long sa = ((Range *)a)->start;
    long long sb = ((Range *)b)->start;
    return (sa > sb) - (sa < sb);
}

int main() {
    Range ranges[1000];
    int range_count = 0;

    char line[1024];
    while (fgets(line, sizeof(line), stdin)) {
        if (line[0] == '\n') {
            break;
        }
        sscanf(line, "%lld-%lld", &ranges[range_count].start, &ranges[range_count].end);
        range_count++;
    }

    qsort(ranges, range_count, sizeof(Range), cmp_ranges);

    long long total = 0;
    long long cur_start = ranges[0].start;
    long long cur_end = ranges[0].end;

    for (int i = 1; i < range_count; i++) {
        if (ranges[i].start <= cur_end + 1) {
            if (ranges[i].end > cur_end) {
                cur_end = ranges[i].end;
            }
        } else {
            total += cur_end - cur_start + 1;
            cur_start = ranges[i].start;
            cur_end = ranges[i].end;
        }
    }
    total += cur_end - cur_start + 1;

    printf("%lld\n", total);
    return 0;
}
