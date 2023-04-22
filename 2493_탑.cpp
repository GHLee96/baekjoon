#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    int h;
    stack<pair<int, int>> st;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> h;
        while (!st.empty() && st.top().first < h) st.pop();

        if (st.empty())
            cout << "0 ";
        else
            cout << st.top().second << " ";

        st.push({h, i});
    }

    return 0;
}