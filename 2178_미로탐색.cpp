#include <iostream>
#include <queue>
using namespace std;

char map[101][101];
int n, m;
int visited[101][101];
struct Node {
    int row;
    int col;
};
queue<Node> q;
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

void bfs() {

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = now.row + dr[i];
            int nc = now.col + dc[i];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                continue;
            if (map[nr][nc] == '0')
                continue;
            if (visited[nr][nc] != '0')
                continue;
            // if (visited[nr][nc] < visited[now.row][now.col] + 1)
            //     continue;

            visited[nr][nc] = visited[now.row][now.col] + 1;
            q.push({nr, nc});
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];

    q.push({0, 0});
    visited[0][0] = 1;
    bfs();

    cout << visited[n - 1][m - 1];

    return 0;
}