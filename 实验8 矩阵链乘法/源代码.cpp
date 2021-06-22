#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

const int inf = 0x3f3f3f3f;
const int N = 1e3 + 7;

int p[N], dp[N][N];

int n;

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    n--;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            dp[i][j] = inf;
        }
    }
    for (int len = 2; len <= n; ++len) {
        for (int i = 1; i + len - 1 <= n; ++i) {
            int j = i + len - 1;
            for (int k = i; k < j; ++k) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + p[i - 1] * p[j] * p[k]);
            }
        }
    }
    cout << dp[1][n] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
/*
4
10 100 5 50
*/