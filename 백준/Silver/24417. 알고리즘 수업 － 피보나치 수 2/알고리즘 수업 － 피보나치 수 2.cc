#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    long long a = 0;
    long long b = 1;
    long long res = 0;
    for(int i = 2; i <= n; i++) {
        res = (a + b) % 1000000007;
        a = b;
        b = res;
    }
    
    cout << res << ' ' << n - 2 << endl;
    
    return 0;
}