#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

const int N = 1e3 + 7;

int w[N][N];
int dp[N][N];

int n, m, k;

void solve() {
    cin >> n >> k >> m;  // n个项目，每个项目能投资0~k，资金m
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            cin >> w[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++ j) {
            if (j > i * k) break;
            dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; ++i) { // 第i个项目
        for (int j = 1; j <= m; ++j) { // 总共花费j
            if (j > i * k) break;
            for (int q = min(k, j); q >= 0; --q) { // 第i个项目花费q
                dp[i][j] = max(dp[i][j], dp[i - 1][j - q] + w[i][q]);
            }
        }
    }
    if (m > n * k) m = n * k; // 特判，当然也可以在转移方程时多一步
    cout << dp[n][m] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
/*
5 5 10
1 2 3 4 5
11 12 13 14 15
0 5 10 15 20
2 10 30 32 40
20 21 22 23 24
*/