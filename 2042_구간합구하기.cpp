#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    arr.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    return 0;
}