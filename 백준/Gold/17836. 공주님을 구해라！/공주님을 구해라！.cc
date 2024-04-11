#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct info {
	int r, c, cnt;
};

int N, M, T;

int map[105][105];
vector<vector<int>> visit;

int dr[4] = { 0, 0, -1, 1 };
int dc[4] = { 1, -1, 0, 0 };

void input() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> T;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
}

bool is_valid(info now) {
	return now.r < 0 || now.r >= N || now.c < 0 || now.c >= M;
}

int get_min_time() {
	int jump = 0x7fffffff;

	queue<info> q;
	q.push({ 0, 0, 0 });

	visit.resize(N + 5, vector<int>(M + 5, 0x7fffffff));
	visit[0][0] = 0;

	while (!q.empty()) {
		info now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			info next;
			next.r = now.r + dr[i];
			next.c = now.c + dc[i];

			if (is_valid(next)) continue;
			if (visit[next.r][next.c] != 0x7fffffff) continue;

			visit[next.r][next.c] = now.cnt + 1;
			next.cnt = now.cnt + 1;

			if (map[next.r][next.c] == 1) continue;
			if (map[next.r][next.c] == 2) {
				jump = next.cnt + abs(next.r - (N - 1)) + abs(next.c - (M - 1));
				continue;
			}

			q.push(next);
		}
	}

	int res = min(visit[N - 1][M - 1], jump);
	if (T < res || res <= 1)
		res = -1;
		
	return res;
}


int main() {
	input();
	int res = get_min_time();
	
	if (res == -1) cout << "Fail" << endl;
	else cout << res << endl;

	return 0;
}