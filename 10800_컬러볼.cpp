#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef struct INFO {
    int color, size, num;
} info;

bool cmp(info &a, info &b) {
    if (a.size == b.size) return a.color < b.color;
    return a.size < b.size;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int N;
    cin >> N;

    vector<info> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i].color >> v[i].size;
        v[i].num = i;
    }

    sort(v.begin(), v.end(), cmp);
    int arr[200001] = {
        0,
    };

    int sum = 0;
    int n_same = 1;

    vector<int> res(N);

    res[v[0].num] = 0;
    arr[v[0].color] += v[0].size;
    for (int i = 1; i < N; i++) {
        if (v[i].size != v[i - 1].size) {
            sum += v[i - 1].size * n_same;
            n_same = 1;

            res[v[i].num] = sum - arr[v[i].color];
            arr[v[i].color] += v[i].size;
        } else {
            n_same++;

            if (v[i].color != v[i - 1].color) {
                res[v[i].num] = sum - arr[v[i].color];
            } else {
                res[v[i].num] = res[v[i - 1].num];
            }
            arr[v[i].color] += v[i].size;
        }
    }

    for (auto x : res) {
        cout << x << "\n";
    }

    return 0;
}