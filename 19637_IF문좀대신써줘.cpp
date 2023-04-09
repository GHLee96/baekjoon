#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
vector<pair<int, string>> info;

int my_search(int power) {
    int size = info.size();
    int mid;
    int s = 0;
    int e = size - 1;
    while (s <= e) {
        mid = (s + e) / 2;
        if (info[mid].first >= power) {
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }

    if (power > info[mid].first)
        return mid + 1;
    else
        return mid;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string str;
        int value;
        cin >> str >> value;
        if (i > 0)
            if (value == info.back().first) continue;

        info.push_back({value, str});
    }

    int max = 0;
    for (int j = 0; j < M; j++) {
        int power;
        cin >> power;

        cout << info[my_search(power)].second << "\n";
    }

    return 0;
}