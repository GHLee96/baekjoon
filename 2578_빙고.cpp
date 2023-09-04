#include <cstring>
#include <iostream>
#include <string>

using namespace std;

int map[5][5];

struct Coord {
    int r, c;
} coord[26];

int row[5];
int col[5];
int diagonal[2];

const int FULL = 0x1f;

void input() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int val;
            cin >> val;

            coord[val].r = i;
            coord[val].c = j;
        }
    }
}

int main() {
    input();

    int bingo_cnt = 0;
    for (int i = 0; i < 25; i++) {
        int val;
        cin >> val;

        int r = coord[val].r;
        int c = coord[val].c;

        row[r] |= 1 << c;
        col[c] |= 1 << r;
        if (r == c) {
            diagonal[0] |= 1 << r;
            if (diagonal[0] == FULL) bingo_cnt++;
        }
        if (c == 4 - r) {
            diagonal[1] |= 1 << r;
            if (diagonal[1] == FULL) bingo_cnt++;
        }

        if (row[r] == FULL) bingo_cnt++;
        if (col[c] == FULL) bingo_cnt++;

        if (bingo_cnt >= 3) {
            cout << i + 1;
            break;
        }
    }

    return 0;
}