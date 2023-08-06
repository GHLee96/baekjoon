#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct info {
    int dist, start, end;
};

int N, M;
int num_island;
vector<vector<int>> map;
vector<vector<bool>> visit;
vector<info> bridge;  // distance, island

vector<vector<pair<int, int>>> coord_island;
vector<pair<int, int>> each_coord_island;

vector<int> parent;

int dr[] = {0, 0, -1, 1};
int dc[] = {-1, 1, 0, 0};

bool is_map(int r, int c) { return (r >= 0 && r < N && c >= 0 && c < M); }

bool cmp(info a, info b) { return a.dist < b.dist; }

void set_island_group(int r, int c, int num) {
    visit[r][c] = true;
    map[r][c] = num;
    each_coord_island.push_back({r, c});

    for (int i = 0; i < 4; i++) {
        int tr = r + dr[i];
        int tc = c + dc[i];
        if (!is_map(tr, tc)) continue;
        if (visit[tr][tc]) continue;

        if (map[tr][tc] == 1) {
            set_island_group(tr, tc, num);
        }
    }
}

void set_island() {
    num_island = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visit[i][j] && map[i][j] == 1) {
                each_coord_island.clear();
                set_island_group(i, j, num_island++);
                coord_island.push_back(each_coord_island);
            }
        }
    }
    num_island--;
}

void get_bridge() {
    for (int i = 0; i < num_island; i++) {
        for (auto x : coord_island[i]) {
            for (int j = 0; j < 4; j++) {
                int start = i + 1;
                int dis = 0;

                int tr = x.first + dr[j];
                int tc = x.second + dc[j];

                if (!is_map(tr, tc)) continue;
                if (map[tr][tc] != 0) continue;

                bool flag = true;
                while (map[tr][tc] == 0) {
                    tr += dr[j];
                    tc += dc[j];
                    dis++;
                    if (!is_map(tr, tc)) {
                        flag = false;
                        break;
                    }
                }
                if (!flag) continue;
                if (map[tr][tc] == start) continue;

                if (dis == 1) continue;
                bridge.push_back({dis, start, map[tr][tc]});
            }
        }
    }
    return;
}

int get_parent(int i) {
    if (parent[i] == i) return i;
    return parent[i] = get_parent(parent[i]);
}

bool union_set(int i, int j) {
    i = get_parent(i);
    j = get_parent(j);

    if (i == j) return false;
    parent[i] = parent[j];
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    map.resize(N, vector<int>(M));
    visit.resize(N, vector<bool>(N, false));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    set_island();
    get_bridge();

    sort(bridge.begin(), bridge.end(), cmp);
    parent.resize(num_island + 1);
    for (int i = 1; i <= num_island; i++) {
        parent[i] = i;
    }

    int min_dist = 0;
    for (int i = 0; i < bridge.size(); i++) {
        if (union_set(bridge[i].start, bridge[i].end))
            min_dist += bridge[i].dist;
    }

    for (int i = 1; i <= num_island; i++) {
        get_parent(i);
    }
    parent.erase(unique(parent.begin(), parent.end()), parent.end());

    if (parent.size() != 2)
        cout << -1;
    else
        cout << min_dist;

    return 0;
}