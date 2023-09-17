#include <iostream>
#include <string>
using namespace std;

int main() {
    string x;
    cin >> x;

    int i = 0;
    bool res = false;
    do {
        int len = x.size();
        string val = to_string((x[0] - '0') * len);

        if (x == val) {
            res = true;
            break;
        }

        x = val;
    } while (++i < 100000);

    if (res)
        cout << "FA";
    else
        cout << "NFA";
    return 0;
}