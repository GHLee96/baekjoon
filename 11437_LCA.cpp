#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1;

    for (int i = 1; i <= T; i++) {
        int N;
        int parent, child;
        int node1, node2;

        cin >> N;

        vector<int> graph(N + 1);

        for (int j = 1; j < N; j++) {
            cin >> parent >> child;
            graph[child] = parent;
        }

        int M;
        cin >> M;
        for (int j = 0; j < M; j++) {
            cin >> node1 >> node2;
            stack<int> st1;
            stack<int> st2;

            child = node1;
            st1.push(child);
            while (graph[child] != 0) {
                st1.push(graph[child]);
                child = graph[child];
            }

            child = node2;
            st2.push(child);
            while (graph[child] != 0) {
                st2.push(graph[child]);
                child = graph[child];
            }

            int nca;
            while (!st1.empty() && !st2.empty()) {
                if (st1.top() != st2.top()) break;
                nca = st1.top();
                st1.pop();
                st2.pop();
            }

            cout << nca << "\n";
        }
    }
    return 0;
}