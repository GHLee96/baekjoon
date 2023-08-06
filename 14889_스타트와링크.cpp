#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> table;
int n;
vector<int> team;
int res_min = 0x7fffffff;

void combi(int idx, int cnt, int sum_a, int sum_b) {
    if (cnt == n / 2) {
        res_min = min(res_min, abs(sum_a - sum_b));
        return;
    }

    int origin_sum_a = sum_a;
    int origin_sum_b = sum_b;
    for (int i = idx + 1; i <= n; i++) {
        team[i] = 1;

        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (team[j]) {
                sum_a += table[i][j] + table[j][i];
            } else {
                sum_b -= table[i][j] + table[j][i];
            }
        }

        combi(i, cnt + 1, sum_a, sum_b);
        team[i] = 0;

        sum_a = origin_sum_a;
        sum_b = origin_sum_b;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    int total_sum = 0;
    table.resize(n + 1, vector<int>(n + 1));
    team.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> table[i][j];
            total_sum += table[i][j];
        }
    }

    combi(0, 0, 0, total_sum);
    cout << res_min;

    return 0;
}