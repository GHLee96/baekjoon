#include <iostream>
#include <map>
#include <string>

using namespace std;

class Trie {
  public:
    string name;
    map<string, Trie *> child;

    Trie() : name(""){};
    Trie(string name) : name(name){};
};

int N, K;
string str[20];

void insert(Trie *trie, int idx) {

    if (idx == K)
        return;

    if (trie->child.count(str[idx]) == 0) {
        // 없으면 정점 만들기

        Trie *new_trie = new Trie(str[idx]);
        trie->child[str[idx]] = new_trie;
    }

    insert(trie->child[str[idx]], idx + 1);
}

void dfs(Trie *trie, int depth) {
    for (int i = 0; i < depth; i++)
        cout << "--";

    if (depth != -1) {
        cout << trie->name << '\n';
    }
    for (auto x : trie->child) {
        dfs(x.second, depth + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    Trie *head = new Trie();

    for (int i = 0; i < N; i++) {
        cin >> K;

        for (int j = 0; j < K; j++) {
            cin >> str[j];
        }

        insert(head, 0);
    }

    dfs(head, -1);

    delete head;
    return 0;
}