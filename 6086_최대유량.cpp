#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 그래프의 인접 리스트 표현을 위한 구조체
struct Edge {
    int v;            // 도착 정점
    int capacity;     // 간선의 용량
    int flow;         // 현재 흐르고 있는 유량
    int reverseEdge;  // 역방향 간선의 인덱스
};

class MaxFlow {
   private:
    int V;                       // 정점의 수
    vector<vector<Edge>> graph;  // 그래프의 인접 리스트
    vector<int> parent;          // 최단 경로 상에서 각 정점의 부모
    vector<int> pathFlow;  // 최단 경로 상에서 흐를 수 있는 최대 유량

   public:
    MaxFlow(int vertexCount) {
        V = vertexCount;
        graph.resize(V);
        parent.resize(V);
        pathFlow.resize(V);
    }

    // 간선을 그래프에 추가하는 함수
    void addEdge(int u, int v, int capacity) {
        // 존재하는 간선인 경우, 유량 더하기
        for (auto& edge : graph[u]) {
            if (edge.v == v) {
                edge.capacity += capacity;

                for (auto& redge : graph[v]) {
                    if (redge.v == u) {
                        redge.capacity += capacity;
                    }
                }
                return;
            }
        }

        Edge forwardEdge = {v, capacity, 0, static_cast<int>(graph[v].size())};
        Edge reverseEdge = {u, capacity, 0, static_cast<int>(graph[u].size())};
        graph[u].push_back(forwardEdge);
        graph[v].push_back(reverseEdge);
    }

    // 최대 유량을 구하는 함수
    int findMaxFlow(int source, int sink) {
        int maxFlow = 0;

        while (bfs(source, sink)) {
            int flow = INT_MAX;
            int v = sink;

            // 최소 경로 상에서의 최소 유량을 찾음
            while (v != source) {
                int u = parent[v];
                int idx = pathFlow[v];
                flow = min(flow, graph[u][idx].capacity - graph[u][idx].flow);
                v = u;
            }

            // 경로 상의 간선에 유량을 증가시킴
            v = sink;
            while (v != source) {
                int u = parent[v];
                int idx = pathFlow[v];
                graph[u][idx].flow += flow;
                graph[v][graph[u][idx].reverseEdge].flow -= flow;
                v = u;
            }

            maxFlow += flow;
        }

        return maxFlow;
    }

   private:
    bool bfs(int source, int sink) {
        fill(parent.begin(), parent.end(), -1);
        fill(pathFlow.begin(), pathFlow.end(), -1);

        queue<int> q;
        q.push(source);
        parent[source] = -2;
        pathFlow[source] = -1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int i = 0; i < graph[u].size(); i++) {
                int v = graph[u][i].v;
                int capacity = graph[u][i].capacity;
                int flow = graph[u][i].flow;

                if (parent[v] == -1 && capacity > flow) {
                    q.push(v);
                    parent[v] = u;
                    pathFlow[v] = i;
                }
            }
        }

        return parent[sink] != -1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;

    MaxFlow maxFlow(26 * 2);

    for (int i = 0; i < N; i++) {
        char u, v;
        int cap, s, e;

        cin >> u >> v >> cap;

        if (u >= 'A' && u <= 'Z')
            s = u - 'A';
        else
            s = u - 'a' + 26;

        if (v >= 'A' && v <= 'Z')
            e = v - 'A';
        else
            e = v - 'a' + 26;
        maxFlow.addEdge(s, e, cap);
    }

    cout << maxFlow.findMaxFlow(0, 25);
    return 0;
}