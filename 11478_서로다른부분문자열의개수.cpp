#include <cstring>
#include <iostream>
#include <set>
#include <vector>

using namespace std;
string str;
set<string> s;

int main() {
    cin >> str;

    int len = str.length();
    set<string> s;
    for (int i = 0; i < len; i++) {
        string a;

        for (int j = i; j < len; j++) {
            a.push_back(str[j]);
            s.insert(a);
        }
    }
    cout << s.size();
    return 0;
}