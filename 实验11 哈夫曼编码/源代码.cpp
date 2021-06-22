#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

const int inf = 0x3f3f3f3f;
const int N = 1e3 + 7;

int n;
int fa[N], ww[N];
vector<int> son[N];

struct Node {
    int id, w;
    bool operator < (const Node &a) const {
        return w > a.w;
    }
};

void solve() {
    scanf("%d", &n);
    priority_queue<Node> q;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &ww[i]);
        q.push({i, ww[i]});
    }
    while (q.size() > 1) {
        Node l = q.top();
        q.pop();
        Node r = q.top();
        q.pop();
        int id = ++n, w = l.w + r.w;
        ww[id] = w;
        fa[l.id] = id, fa[r.id] = id;
        son[id].push_back(l.id);
        son[id].push_back(r.id);
        q.push({id, w});
    }
    fa[q.top().id] = -1;
    q.pop();
    for (int i = 1; i <= n; ++i) {
        printf("id:%d\tweight:%d\tparent:%d\t", i, ww[i], fa[i]);
        if (son[i].size() == 0) {
            printf("lson:-1\trson:-1\n");
        } else {
            printf("lson:%d\trson:%d\n", son[i][0], son[i][1]);
        }
    }
}

int main() {
    // scanf("%d", &t);
    int t = 1;
    while (t--) solve();
    return 0;
}
/*
8
5 5 10 10 10 15 20 25
*/