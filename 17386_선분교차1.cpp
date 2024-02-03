#include <iostream>

using namespace std;

struct Point {
    long long x, y;

    bool operator>(const Point &other) const {
        if (x > other.x) {
            return true;
        } else if (x == other.x) {
            return y > other.y;
        } else {
            return false;
        }
    }

    bool operator<=(const Point &other) const { return !(*this > other); }
};

Point p1, p2, p3, p4;

int ccw(Point p1, Point p2, Point p3) {
    long long result =
        (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y);
    if (result > 0)
        return 1; // 반시계 방향
    else if (result < 0)
        return -1; // 시계 방향
    else
        return 0; // 일직선
}

bool isIntersect(Point p1, Point p2, Point p3, Point p4) {
    int abc = ccw(p1, p2, p3) * ccw(p1, p2, p4);
    int cda = ccw(p3, p4, p1) * ccw(p3, p4, p2);

    if (abc == 0 && cda == 0) {
        if (p1 > p2)
            swap(p1, p2);
        if (p3 > p4)
            swap(p3, p4);
        return p3 <= p2 && p1 <= p4;
    }

    return abc <= 0 && cda <= 0;
}

int main() {
    cin >> p1.x >> p1.y >> p2.x >> p2.y;

    cin >> p3.x >> p3.y >> p4.x >> p4.y;

    bool isCross = isIntersect(p1, p2, p3, p4);

    cout << isCross << '\n';

    return 0;
}
