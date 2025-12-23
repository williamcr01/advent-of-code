#include <stdio.h>

int lines = 4413;
int dial_val = 50;
int zero_cnt = 0;

typedef struct {
    char dir;
    int val;
} Instruction;

int main() {
    Instruction instruction[lines];
    char dir;
    int val;
    int i;
    for (i = 0; i < lines; i++) {
        scanf(" %c%d", &dir, &val);
        instruction[i].dir = dir;
        instruction[i].val = val;
    }
    for (i = 0; i < lines; i++) {
        val = instruction[i].val % 100;
        if (instruction[i].dir == 'L') {
            if (dial_val - val < 0) {
                val -= (dial_val + 1);
                dial_val = 99;
            }
            dial_val -= val;
        } else if (instruction[i].dir == 'R') {
            if (dial_val + val > 99) {
                val -= (100 - dial_val);
                dial_val = 0;
            }
            dial_val += val;
        }
        if (dial_val == 0) {
            zero_cnt++;
        }
    }
    printf("Zero count: %d", zero_cnt);

    return 0;
}
