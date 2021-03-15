#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 7;
const int inf = 0x3f3f3f3f;

int dis[N][N], d[N], vis[N];
int n, m, u, v, w;

int prim() {
    int ans = 0;
    d[1] = 0;
    for (int i = 1; i <= n; ++i) {
        int nxt = -1, mind = 0x3f3f3f;
        for (int j = 1; j <= n; ++j) {
            if (vis[j]) continue;
            if (d[j] < mind) {
                nxt = j;
                mind = d[j];
            }
        }
        if (nxt == -1) return -1;
        vis[nxt] = 1;
        ans += mind;
        for (int j = 1; j <= n; ++j) {
            if (!vis[j]) d[j] = min(d[j], dis[nxt][j]);
        }
    }
    return ans;
}

int main() {
    memset(dis, 0x3f, sizeof(dis));
    memset(d, 0x3f, sizeof(d));
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        dis[u][v] = w;
        dis[v][u] = w;
    }
    printf("%d\n", prim());
    return 0;
}
/*
4 5
1 2 4
1 3 6
1 4 3
2 3 1
2 4 2
*/