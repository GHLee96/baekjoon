#include <cstring>
#include <iostream>
#include <string>

using namespace std;

string ans;
string bridge[2];

int cnt;
int len;

int dp[2][101][21];

int dfs(int idx, int depth, int bridge_i) {
    if (depth == ans.size()) {
        return 1;
    }

    int &ret = dp[bridge_i][idx][depth];
    if (ret != -1) return ret;

    ret = 0;

    for (int i = idx; i < len; i++) {
        if (ans[depth] != bridge[bridge_i][i]) continue;

        ret += dfs(i + 1, depth + 1, (bridge_i + 1) % 2);
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> ans;
    cin >> bridge[0] >> bridge[1];

    memset(dp, -1, sizeof(dp));
    len = bridge[0].size();
    cnt += dfs(0, 0, 0);
    cnt += dfs(0, 0, 1);
    cout << cnt;

    return 0;
}