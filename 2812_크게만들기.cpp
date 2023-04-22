#include <cstring>
#include <iostream>

using namespace std;

int main() {
    int N, K;
    string str;
    cin >> N >> K;
    cin >> str;

    int size = str.length();
    int cnt = 0;
    string res = "";

    for (int i = 0; i < size; i++) {
        while (res.back() < str[i] && i > 0 && res.size() != 0 && cnt < K) {
            res.pop_back();
            cnt++;
        }
        if (cnt == K) {
            res += str.substr(i);
            break;
        }
        res += str[i];
    }
    // res.resize(size - K); // resize는 size-K가 size보다 작은지 확인이 필요
    res.erase(size - K);
    cout << res;
    return 0;
}