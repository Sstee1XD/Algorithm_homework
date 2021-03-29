#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
const int N = 1e4 + 7;

int a[N], n, x;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &x);
    int pos = 1;
    for (int i = 14; i >= 0; --i) {
        if (pos + (1 << i) > n) continue;
        if (a[pos + (1 << i)] <= x) {
            pos += 1 << i;
        }
    }
    if (a[pos] == x) {
        printf("%d\n", pos);
    } else {
        puts("0");
    }
    return 0;
}
