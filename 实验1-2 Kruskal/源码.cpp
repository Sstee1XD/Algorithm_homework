#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 7;
const int inf = 0x3f3f3f3f;

struct Edge {
    int u, v, w;

    bool operator < (const Edge &a) const {
        return w < a.w;
    }

    Edge () {}
    Edge (int u, int v, int w) : u(u), v(v), w(w) {}
}e[N];

int n, m, u, v, w;
int fa[N], sz[N];

int find(int x) {
    return x == fa[x]? x : fa[x] = find(fa[x]);
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x != y) {
        if (sz[x] < sz[y]) fa[x] = y, sz[y] += sz[x];
        else fa[y] = fa[x], sz[x] += sz[y];
    }
}

int kruskal() {
    int ans = 0;
    sort(e + 1, e + 1 + m);
    int cnt = 0;
    for (int i = 1; i <= m; ++i) {
        int u = e[i].u, v = e[i].v;
        if (find(u) == find(v)) continue;
        merge(u, v);
        cnt++;
        ans += e[i].w;
        if (cnt == n - 1) return ans;
    }
    return -1;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
        sz[i] = 1;
    }
    for (int i = 1; i <= m; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        e[i] = Edge(u, v, w);
    }
    printf("%d\n", kruskal());
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