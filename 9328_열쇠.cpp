#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

int R, C;
vector<vector<char>> map;
vector<vector<bool>> visit;
string key;
int res;

bool is_map(int r, int c) {
    if (r >= 0 && r < R && c >= 0 && c < C) return true;
    return false;
}

queue<pair<int, int>> q;

void find_entrance() {
    for (int coner : {0, R - 1}) {
        for (int i = 0; i < C; i++) {
            visit[coner][i] = true;

            if (map[coner][i] == '*') continue;
            if (map[coner][i] == '.')
                q.push({coner, i});
            else if (map[coner][i] >= 'A' && map[coner][i] <= 'Z') {
                for (char x : key) {
                    if (map[coner][i] == toupper(x)) {
                        q.push({coner, i});
                    }
                }
            } else if (map[coner][i] >= 'a' && map[coner][i] <= 'z') {
                if (key.find(map[coner][i]) == string::npos)
                    key += map[coner][i];
                q.push({coner, i});
            } else if (map[coner][i] == '$') {
                q.push({coner, i});
                res++;
            }
        }
    }

    for (int coner : {0, C - 1}) {
        for (int i = 1; i < R - 1; i++) {
            visit[i][coner] = true;

            if (map[i][coner] == '*') continue;
            if (map[i][coner] == '.')
                q.push({i, coner});
            else if (map[i][coner] >= 'A' && map[i][coner] <= 'Z') {
                for (char x : key) {
                    if (map[i][coner] == toupper(x)) {
                        q.push({i, coner});
                    }
                }
            } else if (map[i][coner] >= 'a' && map[i][coner] <= 'z') {
                if (key.find(map[i][coner]) == string::npos)
                    key += map[i][coner];
                q.push({i, coner});
            } else if (map[i][coner] == '$') {
                q.push({i, coner});
                res++;
            }
        }
    }
}

int sol() {
    int tr;
    int tc;
    int n_key = key.size();

    res = 0;
    visit.clear();
    visit.resize(R, vector<bool>(C, false));

    find_entrance();
    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        visit[cr][cc] = true;

        for (int i = 0; i < 4; i++) {
            tr = cr + dr[i];
            tc = cc + dc[i];

            if (is_map(tr, tc) && !visit[tr][tc]) {
                visit[tr][tc] = true;

                if (map[tr][tc] == '*') continue;
                if (map[tr][tc] == '.')
                    q.push({tr, tc});
                else if (map[tr][tc] >= 'A' && map[tr][tc] <= 'Z') {
                    for (char x : key) {
                        if (map[tr][tc] == toupper(x)) {
                            q.push({tr, tc});
                        }
                    }
                } else if (map[tr][tc] >= 'a' && map[tr][tc] <= 'z') {
                    if (key.find(map[tr][tc]) == string::npos)
                        key += map[tr][tc];
                    q.push({tr, tc});
                } else if (map[tr][tc] == '$') {
                    q.push({tr, tc});
                    res++;
                }
            }
        }
    }

    if (n_key != key.size()) sol();

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> R >> C;
        map.clear();
        map.resize(R, vector<char>(C));
        visit.clear();
        visit.resize(R, vector<bool>(C, false));
        for (int j = 0; j < R; j++) {
            for (int k = 0; k < C; k++) {
                cin >> map[j][k];
            }
        }
        cin >> key;
        if (key[0] == '0') {
            key.clear();
        }

        sol();
        cout << res << "\n";
    }
    return 0;
}