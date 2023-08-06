#include <iostream>

using namespace std;

struct Point {
    double x, y;

    // ">" 연산자 오버로딩
    bool operator>(const Point& other) const {
        if (x > other.x) {
            return true;
        } else if (x == other.x) {
            return y > other.y;
        } else {
            return false;
        }
    }

    // "<=" 연산자 오버로딩
    bool operator<=(const Point& other) const { return !(*this > other); }
};

Point p1, p2, p3, p4;
const double INF = 987654321;

int ccw(Point p1, Point p2, Point p3) {
    double result =
        (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y);
    if (result > 0)
        return 1;  // 반시계 방향
    else if (result < 0)
        return -1;  // 시계 방향
    else
        return 0;  // 일직선
}

bool isIntersect(Point p1, Point p2, Point p3, Point p4) {
    int abc = ccw(p1, p2, p3) * ccw(p1, p2, p4);
    int cda = ccw(p3, p4, p1) * ccw(p3, p4, p2);

    if (abc == 0 && cda == 0) {
        if (p1 > p2) swap(p1, p2);
        if (p3 > p4) swap(p3, p4);
        if (p3 <= p2 && p1 <= p4)
            return 1;
        else
            return 0;
    }

    return abc <= 0 && cda <= 0;
}

Point getIntersection(Point p1, Point p2, Point p3, Point p4) {
    double A1 = p2.y - p1.y;
    double B1 = p1.x - p2.x;
    double C1 = A1 * p1.x + B1 * p1.y;

    double A2 = p4.y - p3.y;
    double B2 = p3.x - p4.x;
    double C2 = A2 * p3.x + B2 * p3.y;

    double det = A1 * B2 - A2 * B1;

    if (det == 0) {
        // if (p1 > p2) swap(p1, p2);
        // if (p3 > p4) swap(p3, p4);

        // if (p1.x == p3.x && p1.y == p3.y) {
        //     if (p1 > p2 && p3 > p1 || p1 > p3 && p2 > p1)
        //         return p1;
        //     else if (p1.x == p4.x && p1.y == p4.y)
        //         if (p1 > p2 && p4 > p1 || p1 > p4 && p2 > p1) return p1;
        // }
        if (p1 > p2) swap(p1, p2);
        if (p3 > p4) swap(p3, p4);

        if (p2.x == p3.x && p2.y == p3.y) {
            if (p3 > p1 || (p3.x == p1.x && p3.y == p1.y)) return p2;
        }

        if (p1.x == p4.x && p1.y == p4.y) {
            if (p1 > p3 || (p1.x == p3.x && p1.y == p3.y)) return p1;
        }

        return {INF, INF};
    } else {
        // 교차점 계산
        double x = (C1 * B2 - C2 * B1) / det;
        double y = (A1 * C2 - A2 * C1) / det;
        return {x, y};
    }
}

int main() {
    // L1의 양 끝 점 입력
    cin >> p1.x >> p1.y >> p2.x >> p2.y;

    // L2의 양 끝 점 입력
    cin >> p3.x >> p3.y >> p4.x >> p4.y;

    // 두 선분이 교차하는지 확인
    bool isCross = isIntersect(p1, p2, p3, p4);

    cout << isCross << '\n';
    if (isCross) {
        // 교차하는 경우 교차점 계산 및 출력
        Point intersection = getIntersection(p1, p2, p3, p4);

        cout << fixed;
        cout.precision(10);
        if (intersection.x != INF)
            cout << intersection.x << ' ' << intersection.y << '\n';
    }

    return 0;
}
