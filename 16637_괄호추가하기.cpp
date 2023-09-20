#include <iostream>
#include <string>

using namespace std;

int N;
int digit[20];
char op[20];

int res_digit[20];
char res_op[20];

int max_res = 0x80000000;

void input() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        if (i % 2 == 0)
            cin >> digit[i / 2];
        else
            cin >> op[i / 2];
    }
}

int calculate(int a, int b, char c) {

    if (c == '+') {
        return a + b;
    } else if (c == '-') {
        return a - b;
    } else if (c == '*') {
        return a * b;
    }

    return 0;
}

void solution(int idx, int d) {
    if (idx > N / 2) {
        // 계산

        int res = res_digit[0];
        for (int i = 1; i < d; i++) {
            res = calculate(res, res_digit[i], res_op[i - 1]);
        }

        max_res = max(max_res, res);
        return;
    }

    res_digit[d] = digit[idx];
    res_op[d] = op[idx];
    solution(idx + 1, d + 1);

    if (idx != N / 2) {
        int val = calculate(digit[idx], digit[idx + 1], op[idx]);
        res_digit[d] = val;
        res_op[d] = op[idx + 1];
        solution(idx + 2, d + 1);
    }
}

int main() {
    input();
    solution(0, 0);

    cout << max_res;
    return 0;
}
