#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct info {
    int num, group;
};

struct cmp1 {
    bool operator()(info l, info r) {
        if (l.num == r.num)
            return l.group > r.group;
        return l.num > r.num;
    }
};

struct cmp2 {
    bool operator()(info l, info r) {
        if (l.num == r.num)
            return l.group > r.group;
        return l.num < r.num;
    }
};

int N, M, P;

vector<int> idx;
vector<vector<int>> arr;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    arr.resize(N, vector<int>(M));
    idx.resize(N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
        sort(arr[i].begin(), arr[i].end());
    }

    priority_queue<info, vector<info>, cmp1> q_min;
    priority_queue<info, vector<info>, cmp2> q_max;

    for (int i = 0; i < N; i++) {
        q_min.push({arr[i][0], i});
        q_max.push({arr[i][0], i});
        idx[i]++;
    }

    int res = 0x7fffffff;

    while (1) {
        info min_val = q_min.top();
        info max_val = q_max.top();
        q_min.pop();

        res = min(res, max_val.num - min_val.num);

        if (idx[min_val.group] == M)
            break;
        int next_val = arr[min_val.group][idx[min_val.group]];
        q_min.push({next_val, min_val.group});
        q_max.push({next_val, min_val.group});

        idx[min_val.group]++;
    }

    cout << res;

    return 0;
}