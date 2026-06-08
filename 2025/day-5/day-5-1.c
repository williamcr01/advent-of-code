#include <stdio.h>

typedef struct {
    long long start;
    long long end;
} Range;

int main() {
    Range ranges[1000];
    long long ids[1000];
    int range_count = 0;
    int id_count = 0;

    char line[1024];
    while (fgets(line, sizeof(line), stdin)) {
        if (line[0] == '\n') {
            break;
        }
        sscanf(line, "%lld-%lld", &ranges[range_count].start, &ranges[range_count].end);
        range_count++;
    }

    while (fgets(line, sizeof(line), stdin)) {
        sscanf(line, "%lld", &ids[id_count]);
        id_count++;
    }

    int fresh = 0;
    for (int i = 0; i < id_count; i++) {
        for (int j = 0; j < range_count; j++) {
            if (ids[i] >= ranges[j].start && ids[i] <= ranges[j].end) {
                fresh++;
                break;
            }
        }
    }

    printf("%d\n", fresh);
    return 0;
}
