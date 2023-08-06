#include <cmath>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, n;
    const int MAX = 1001;
    int arr[MAX] = {
        0,
    };

    cin >> T;

    cout << fixed;
    cout.precision(3);
    for (int i = 0; i < T; i++) {
        cin >> n;

        double avg = 0;
        int sum = 0;
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            cin >> arr[j];
            sum += arr[j];
        }
        avg = sum / n;

        for (int j = 0; j < n; j++)
            if (avg < arr[j]) cnt++;

        double upper_avg = round((double)cnt / n * 100000) / 1000;
        cout << upper_avg << '%' << "\n";
    }
    return 0;
}