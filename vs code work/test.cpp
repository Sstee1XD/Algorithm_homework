#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 32;
const ll mod = 1e9 + 7;

int dp[N][N][2][2];
int tot1, tot2, dig1[N], dig2[N];
int x, y, ans;

void add(int &a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}

int dfs(int pos, bool lim1, bool lim2, bool ok) {
    if (pos == -1) return ok;
    if (~dp[pos][lim1][lim2][ok]) return dp[pos][lim1][lim2][ok];
    int to1 = lim1? dig1[pos] : 1;
    int to2 = lim2? dig2[pos] : 1;
    int tmp = 0;
    for (int i = 0; i <= to1; ++i) {
        for (int j = 0; j <= to2; ++j) {
            if (i && j) continue;
            int num = dfs(pos - 1, lim1 && i == to1, lim2 && j == to2, ok || i || j);
            add(tmp, num);
            if (!ok && (i || j)) add(ans, (ll)num * (ll)(pos + 1) % mod);
        }
    }
    return dp[pos][lim1][lim2][ok] = tmp;
}

void calc(int x, int y) {
    int len = 0;
    memset(dig1, 0, sizeof(dig1));
    memset(dig2, 0, sizeof(dig2));
    while (x) {
        dig1[len++] = x & 1;
        x >>= 1;
    }
    len = 0;
    while (y) {
        dig2[len++] = y & 1;
        y >>= 1;
    }
    dfs(30, true, true, false);
}

void solve() {
    ans = 0;
    memset(dp, -1, sizeof(dp));
    scanf("%d %d", &x, &y);
    calc(x, y);
    printf("%d\n", ans);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
    return 0;
} 