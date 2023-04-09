#include <cstring>
#include <iostream>

using namespace std;

int N, S;
int arr[100001];

int solution(int idx) {
    int ret = 0x7fffffff;
    int s = 0;
    int e = 0;
    int sum = arr[s];

    while (e < N) {
        if (sum < S) {
            sum += arr[++e];
        } else if (sum >= S) {
            ret = min(ret, e - s + 1);
            sum -= arr[s++];
        }
    }

    if (ret == 0x7fffffff) return 0;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    cout << solution(0);
    return 0;
}