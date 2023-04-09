#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

int dp[10001] = {
    0,
};
vector<int> score;
int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int s;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s;
        score.push_back(s);
    }

    int max_score, min_score;
    for (int i = 0; i < N; i++) {
        max_score = min_score = score[i];
        for (int j = i; j >= 0; j--) {
            max_score = max(max_score, score[j]);
            min_score = min(min_score, score[j]);
            dp[i + 1] = max(dp[i + 1], dp[j] + max_score - min_score);
        }
    }

    cout << dp[N];

    return 0;
}

// #include <iostream>
// #include <algorithm>
// #include <cstring> //memset
// using namespace std;

// const int MAX = 1000;
// const int INF = 987654321;

// int N, result;
// int arr[MAX];
// int cache[MAX]; //idx

// int maxDifference(int idx)
// {
//         //기저 사례: 범위 초과
//         if (idx == N)
//                  return 0;

//         int &result = cache[idx];
//         if (result != -1)
//                  return result;

//         result = 0;
//         int low = INF, high = -1;
//         //조를 나눈다(한명으로 구성된 조도 있다)
//         for (int i = idx; i < N; i++)
//         {
//                  low = min(low, arr[i]);
//                  high = max(high, arr[i]);

//                  result = max(result, (high - low) + maxDifference(i + 1));
//         }
//         return result;
// }

// int main(void)
// {
//         ios_base::sync_with_stdio(0);
//         cin.tie(0); //cin 실행속도
//         cin >> N;

//         for (int i = 0; i < N; i++)
//                  cin >> arr[i];

//         memset(cache, -1, sizeof(cache));
//         cout << maxDifference(0) << "\n";
//         return 0;
// }