#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int L, C;
vector<char> arr;
vector<char> ans;

char vowel[5] = {'a', 'e', 'i', 'o', 'u'};

void combi(int idx, int d, int v_cnt, int c_cnt) {
    if (d == 0) {
        if (v_cnt >= 1 && c_cnt >= 2) {
            for (auto x : ans) cout << x;
            cout << "\n";
        }
        return;
    }

    for (int i = idx; i < C; i++) {
        bool v_check = false;
        for (auto x : vowel) {
            if (x == arr[i]) v_check = true;
        }
        if (v_check)
            v_cnt++;
        else
            c_cnt++;
        ans.push_back(arr[i]);
        combi(i + 1, d - 1, v_cnt, c_cnt);
        ans.pop_back();

        if (v_check)
            v_cnt--;
        else
            c_cnt--;
    }
}

int main() {
    cin >> L >> C;
    arr.resize(C);

    for (int i = 0; i < C; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    combi(0, L, 0, 0);

    return 0;
}