#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> arr;
vector<int> op_arr;
vector<bool> visit;
int num_op[4];  // + - * /
int cnt_op;

int res_max = 0x8fffffff;
int res_min = 0x7fffffff;

void sol(int depth, int sum) {
    if (depth == N) {
        res_max = max(res_max, sum);
        res_min = min(res_min, sum);
        return;
    }

    int origin_sum = sum;
    for (int i = 0; i < cnt_op; i++) {
        if (visit[i]) continue;
        visit[i] = true;

        switch (op_arr[i]) {
            case 0:
                sum += arr[depth];
                break;
            case 1:
                sum -= arr[depth];
                break;
            case 2:
                sum *= arr[depth];
                break;
            case 3:
                sum /= arr[depth];
                break;
        }

        sol(depth + 1, sum);
        visit[i] = false;
        sum = origin_sum;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    arr.resize(N);

    for (int i = 0; i < N; i++) cin >> arr[i];
    for (int i = 0; i < 4; i++) {
        cin >> num_op[i];
        cnt_op += num_op[i];
    }

    visit.resize(cnt_op, false);
    int offset = 0;
    for (int i = 0; i < 4; i++) {
        offset = num_op[i];
        while (offset-- > 0) {
            op_arr.push_back(i);
        }
    }

    sol(1, arr[0]);
    cout << res_max << endl << res_min;

    return 0;
}