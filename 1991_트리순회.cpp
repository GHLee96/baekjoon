#include <math.h>

#include <iostream>
#include <vector>

#define conv(x) (x) - 'A' + 1

using namespace std;
int N;

struct node {
    char l, r;
};

vector<node> map;

void pre(char c) {
    if (c == '.') return;
    cout << c;
    pre(map[c - 'A'].l);
    pre(map[c - 'A'].r);
}

void mid(char c) {
    if (c == '.') return;
    mid(map[c - 'A'].l);
    cout << c;
    mid(map[c - 'A'].r);
}

void back(char c) {
    if (c == '.') return;
    back(map[c - 'A'].l);
    back(map[c - 'A'].r);
    cout << c;
}

int main() {
    cin >> N;

    map.resize(N);

    for (int i = 1; i <= N; i++) {
        char a, l, r;
        cin >> a >> l >> r;

        map[a - 'A'] = {l, r};
    }

    pre('A');
    cout << endl;

    mid('A');
    cout << endl;

    back('A');
    cout << endl;

    return 0;
}