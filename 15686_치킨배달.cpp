#include <iostream>
#include <vector>

using namespace std;

struct coord {
    int r, c;
};

int N, M;
vector<coord> chicken;
vector<coord> home;
vector<int> arr;

int res = 0x7fffffff;

int get_chicken_dis(int h, int c) {
    return abs(home[h].r - chicken[c].r) + abs(home[h].c - chicken[c].c);
}

int sol() {
    int sum = 0;
    for (int i = 0; i < home.size(); i++) {
        int min_dis = 0x7fffffff;
        for (int j = 0; j < arr.size(); j++) {
            min_dis = min(min_dis, get_chicken_dis(i, arr[j]));
        }
        sum += min_dis;
    }
    return sum;
}

// 조합 1
void combi(int arr_idx, int c_idx) {
    if (arr_idx == M) {
        res = min(res, sol());
        return;
    }

    if (c_idx == chicken.size()) {
        return;
    }

    arr[arr_idx] = c_idx;
    combi(arr_idx + 1, c_idx + 1);
    combi(arr_idx, c_idx + 1);
}

// 조합 2
// void combi(int idx, int cnt) {
//     if (cnt == M) {
//         res = min(res, sol());
//         return;
//     }

//     for (int i = idx; i < chicken.size(); i++) {
//         arr.push_back(i);
//         combi(i + 1, cnt + 1);
//         arr.pop_back();
//     }
// }

void input() {
    cin >> N >> M;

    // arr.resize(M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int t;
            cin >> t;
            if (t == 1)
                home.push_back({i, j});
            else if (t == 2)
                chicken.push_back({i, j});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    combi(0, 0);
    cout << res;
    return 0;
}