#include <stdio.h>
#include <stdbool.h>

int main() {
    int fresh = 0;
    
    long long ids[1000];
    long long starts[1000];
    long long ends[1000];

    bool scanning_ranges = true;
    int range_count = 0;
    int id_count = 0;

    char line[1024];
    while (fgets(line, sizeof(line), stdin)) {
        if (line[0] == '\n') {
            scanning_ranges = false;
            continue;
        }
        if (scanning_ranges) {
            long long start, end;
            sscanf(line, "%lld-%lld", &start, &end);

            starts[range_count] = start;
            ends[range_count] = end;
            range_count++;
        } else {
            long long id;
            sscanf(line, "%lld", &id);
            ids[id_count] = id;
            id_count++;
        }
    }

    for (int i = 0; i < id_count; i++) {
        for (int j = 0; j < range_count; j++) {
            if (ids[i] >= starts[j] && ids[i] <= ends[j]) {
                fresh++;
                break;
            }
        }
    }
    printf("Fresh: %d", fresh);
    return 0;
}