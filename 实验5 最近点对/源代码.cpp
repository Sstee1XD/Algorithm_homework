#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

const int N = 2e5 + 7;

struct Point {
    double x, y;
    Point () {}
    Point(double x, double y) : x(x), y(y) {}
}p[N], tmp[N];

bool cmp1(Point a, Point b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

bool cmp2(Point a, Point b) {
    if (a.y == b.y) return a.x < b.x;
    return a.y < b.y;
}

double getDist(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int n;

double gao(int l, int r) {
    int num = r - l + 1;
    if (num == 1) return 1e50;
    if (num == 2) return getDist(p[l], p[r]);
    int mid = l + r >> 1;
    double ans = min(gao(l, mid), gao(mid + 1, r));
    int tot = 0;
    for (int i = l; i <= r; ++i) {
        if (fabs(p[mid].x - p[i].x) <= ans) tmp[++tot] = p[i];
    }
    sort(tmp + 1, tmp + 1 + tot, cmp2);
    for (int i = 1; i <= tot; ++i) {
        for (int j = i + 1; j <= tot; ++j) {
            if (tmp[j].y - tmp[i].y > ans) break;
            ans = min(ans, getDist(tmp[i], tmp[j]));
        }
    }
    return ans;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        double x, y;
        cin >> x >> y;
        p[i] = Point(x, y);
    }
    sort(p + 1, p + 1 + n, cmp1);
    cout << gao(1, n) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cout << fixed << setprecision(4);
    int t = 1;
    while (t--) solve();
    return 0;
}