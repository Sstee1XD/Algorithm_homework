#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

const int inf = 0x3f3f3f3f;
const int N = 1e3 + 7;

int dp[N][N];
int v[N], w[N];
int n, m;

void solve() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", &v[i], &w[i]);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = m; j >= 0; --j) {
            dp[i][j] = dp[i - 1][j];
            if (j < v[i]) continue;
            dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
        }
    }
    int ans = 0;
    for (int j = 1; j <= m; ++j) {
        ans = max(ans, dp[n][j]);
    }
    printf("%d\n", ans);
}

int main() {
    // scanf("%d", &t);
    int t = 1;
    while (t--) solve();
    return 0;
}
/*
6 30
4 605
9 672
14 741
19 812
24 885
30 960
*/