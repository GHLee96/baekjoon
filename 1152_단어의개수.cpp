#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    getline(cin, str);
    int i = 0;

    int first = 0;
    int last = 0;
    int count = 1;

    while(str[i] == ' ') i++;
    first = i;

    i = str.size() - 1;
    while(str[i] == ' ') i--;
    last = i;

    i = first;
    while(i <= last)
    {
        if (str[i] == ' ') count++;
        i++;
    }

    if (first != last)
        cout << count;
    else
        cout << "0";

    return 0;
}