#include <math.h>

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> p;
vector<int> visit;

void make_prime() {
    p.resize(10000);

    p[0] = 1;
    p[1] = 1;

    for (int i = 2; i < 10000; i++) {
        if (p[i]) continue;

        for (int j = i * 2; j < 10000; j += i) {
            p[j] = 1;
        }
    }
}

int pre[10000];

void solution(int a, int b) {
    visit.clear();
    visit.resize(10000);

    queue<pair<int, int>> q;
    q.push({0, a});
    visit[a] = 1;

    int n, c, next;
    while (!q.empty()) {
        n = q.front().first;
        c = q.front().second;
        q.pop();
        visit[c] = 1;

        if (c == b) {
            cout << n << "\n";
            return;
        }

        for (int i = 0; i < 4; i++) {
            for (int k = 0; k <= 9; k++) {
                next = c + pow(10, i) * (k - (c / (int)pow(10, i)) % 10);
                if (next >= 1000 && next <= 9999) {
                    if (!p[next] && !visit[next]) {
                        q.push({n + 1, next});
                        visit[next] = 1;
                        pre[next] = c;

                        if (next == b) {
                            cout << n + 1 << "\n";
                            return;
                        }
                    }
                }
            }
        }
    }
    cout << "Impossible\n";
    return;
}

// void print_route(int a, int b) {
//     while (pre[b] != 0) {
//         cout << pre[b] << " ";
//         b = pre[b];
//     }
// }

int main() {
    int T;
    make_prime();

    cin >> T;
    for (int test_case = 1; test_case <= T; test_case++) {
        int a, b;
        cin >> a >> b;
        solution(a, b);
        // print_route(a, b);
        // cout << endl;
    }
    return 0;
}