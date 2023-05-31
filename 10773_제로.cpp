#include <iostream>
#include <stack>

using namespace std;

int main() {
    int k;
    cin >> k;

    stack<int> st;
    int pre;
    for (int i = 0; i < k; i++) {
        int a;
        cin >> a;
        if (!a)
            st.pop();
        else
            st.push(a);
    }

    long long sum = 0;
    while (!st.empty()) {
        sum += st.top();
        st.pop();
    }
    cout << sum;
}