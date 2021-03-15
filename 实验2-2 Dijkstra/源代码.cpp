#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f;
const int N = 1e2 + 7;

struct Edge {
    int nxt, v, w;

    Edge () {}
    Edge (int nxt, int v, int w) : nxt(nxt), v(v), w(w) {}
}edge[(N * N + N) << 1];

struct qnode {
    int u, w;

    bool operator < (const qnode &a) const {
        return w > a.w;
    }

    qnode () {}
    qnode (int u, int w) : u(u), w(w) {}
};

int dis[N], head[N], vis[N];
int n, m, u, v, w, tot, s, t;

void addedge(int u, int v, int w) {
    edge[tot] = Edge(head[u], v, w);
    head[u] = tot++;
}

void Dijkstra(int s, int t) {
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    dis[s] = 0;
    priority_queue<qnode> q;
    q.push(qnode(s, 0));
    while (!q.empty()) {
        int u = q.top().u;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        if (u == t) return;
        for (int i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].v, w = edge[i].w;
            
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push(qnode(v, dis[v]));
            }
        }
    }
}

int main() {
    tot = 0;
    memset(head, -1, sizeof(head));
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        getchar();
        scanf("%c %c %d", &u, &v, &w);
        u -= 'a';
        v -= 'a';
        addedge(u, v, w);
    }
    getchar();
    scanf("%c %c", &s, &t);
    s -= 'a';
    t -= 'a';
    
    Dijkstra(s, t);
    printf("%d\n", dis[t]);
    return 0;
}
/*
8 11
a b 1
b d 2
c a 2
d c 1
d f 8
e d 2
e g 2
f e 2
g f 3
g h 3
h f 2
a h
*/