#include <cstring>
#include <iostream>
#include <string>

using namespace std;

int arr[26];

int main() {
    string str;
    cin >> str;

    memset(arr, -1, sizeof(arr));

    for (int i = 0; i < str.size(); i++) {
        int k = str[i] - 'a';
        if (arr[k] != -1)
            continue;
        arr[k] = i;
    }

    for (int i = 0; i < 26; i++) {
        cout << arr[i] << ' ';
    }

    return 0;
}