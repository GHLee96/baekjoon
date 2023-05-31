#include <iostream>
#include <stack>

using namespace std;

int main() {
    int N;
    stack<int> st;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int h;
        cin >> h;

        while (!st.empty() && st.top() <= h) {
            st.pop();
        }

        st.push(h);
    }

    cout << st.size();

    return 0;
}