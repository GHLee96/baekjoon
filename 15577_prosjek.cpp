#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << fixed;
    cout.precision(6);

    int N;
    cin >> N;

    priority_queue<double, vector<double>, greater<double>> q;
    for (int i = 0; i < N; i++) {
        double score;
        cin >> score;

        q.push(score);
    }

    double avg = q.top();
    q.pop();
    while (!q.empty()) {
        double min_score = q.top();
        q.pop();

        avg = (avg + min_score) / 2;
    }

    cout << avg << endl;

    return 0;
}