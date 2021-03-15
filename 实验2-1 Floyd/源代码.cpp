#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f;
const int N = 1e2 + 7;

int dis[N][N];
int n, m, u, v, w;

void Floyd() {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
}

int main() {
    memset(dis, 0x3f, sizeof(dis));
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) dis[i][i] = 0;
    for (int i = 1; i <= m; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        dis[u][v] = w;
    }
    Floyd();
    puts("");
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            printf("%d%c", dis[i][j], " \n"[j == n]);
        }
    }
    return 0;
}
/*
4 8
1 2 2
1 3 6
1 4 4
2 3 3
3 1 7
3 4 1
4 1 5
4 3 12
*/