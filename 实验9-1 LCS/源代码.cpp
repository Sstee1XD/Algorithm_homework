#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

const int inf = 0x3f3f3f3f;
const int N = 1e3 + 7;

int dp[N][N];
char a[N], b[N];

void solve() {
    scanf("%s %s", a + 1, b + 1);
    int lena = strlen(a + 1), lenb = strlen(b + 1);
    for (int i = 0; i <= lena; ++i) dp[i][0] = 0;
    for (int j = 0; j <= lenb; ++j) dp[0][j] = 0;
    for (int i = 1; i <= lena; ++i) {
        for (int j = 1; j <= lenb; ++j) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    printf("%d\n", dp[lena][lenb]);
}

int main() {
    // scanf("%d", &t);
    int t = 1;
    while (t--) solve();
    return 0;
}
/*
abcfbc abfcab
*/