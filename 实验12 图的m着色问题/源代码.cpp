#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

const int inf = 0x3f3f3f3f;
const int N = 1e3 + 7;

int n, m, k, tot;
int cor[N];
vector<int> G[N];

bool check(int u) {
    for (auto v : G[u]) {
        if (cor[v] == cor[u]) return false;
    }
    return true;
}

void dfs(int u) {
    if (u > n) {
        printf("case%d:", ++tot);
        for (int i = 1; i <= n; ++i) {
            printf(" %d", cor[i]);
        }
        puts("");
        return;
    }
    for (int i = 1; i <= m; ++i) {
        cor[u] = i;
        if (check(u)) {
            dfs(u + 1);
        }
        cor[u] = 0;
    }
}

void solve() {
    tot = 0;
    scanf("%d %d %d", &n, &m, &k); // 输入点数、颜色数、边数
    for (int i = 1; i <= n; ++i) G[i].clear(), cor[i] = 0;
    for (int i = 1, u, v; i <= k; ++i) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1);
    if (!tot) puts("NO");
}

int main() {
    // scanf("%d", &t);
    int t = 1;
    while (t--) solve();
    return 0;
}
/*
5 3 5
1 2
2 3
3 4
3 5
1 5
*/