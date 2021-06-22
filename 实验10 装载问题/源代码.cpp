#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

const int inf = 0x3f3f3f3f;
const int N = 1e3 + 7;

int c[3], m[3], w[N], path[3][N], vis[N];
int n;

bool dfs(int u) {
    if (u > n) return true;
    for (int i = 1; i <= 2; ++i) {
        if (c[i] + w[u] > m[i]) continue;
        c[i] += w[u];
        path[i][++path[i][0]] = u;
        if (dfs(u + 1)) return true;
        path[i][0]--;
        c[i] -= w[u];
    }
    return false;
}

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &w[i]);
    }
    scanf("%d %d", &m[1], &m[2]);
    if (!dfs(1)) {
        puts("ERROR");
        return;
    }
    for (int i = 1; i <= 2; ++i) {
        printf("%d号轮船装了%d个箱子，总重量为%d，分别是", i, path[i][0], c[i]);
        for (int j = 1; j <= path[i][0]; ++j) {
            printf(" %d号", path[i][j]);
        }
        printf("箱子\n");
    }
}

int main() {
    // scanf("%d", &t);
    int t = 1;
    while (t--) solve();
    return 0;
}
/*
7
90 80 40 30 20 12 10
152 130
*/