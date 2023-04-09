#include <iostream>
#include <vector>

using namespace std;

int p2p_sum(vector<int> V, int begin, int end) {
    int sum = 0;

    for (int i = begin; i <= end; i++) {
        sum += V[i];
    }

    return sum;
}

int n_matched_sum(vector<int> V, int M) {
    int p_begin = 0;
    int p_end = 0;
    int sum;
    int result = 0;
    int size = V.size();

    while (p_end < size) {
        sum = p2p_sum(V, p_begin, p_end);
        if (sum < M) {
            p_end++;
        } else if (sum > M) {
            if (p_begin == p_end) {
                p_end++;
            }
            p_begin++;
        } else {
            result++;
            p_begin++;
            p_end++;
        }
    }
    return result;
}

int main(void) {
    int N, M;
    cin >> N >> M;

    vector<int> A;
    int a;
    for (int i = 0; i < N; i++) {
        cin >> a;
        A.push_back(a);
    }

    cout << n_matched_sum(A, M);

    return 0;
}