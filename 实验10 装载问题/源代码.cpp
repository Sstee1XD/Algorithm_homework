#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

const int inf = 0x3f3f3f3f;
const int N = 1e3 + 7;

int c[3], m[3], w[N], path[3][N], vis[N];
int n;

struct Box {
    int id, w;

    bool operator < (const Box & a) const {
        return w > a.w;
    }
}box[N];

bool dfs(int u) {
    if (u > n) return true;
    for (int i = 1; i <= 2; ++i) {
        if (c[i] + box[u].w > m[i]) continue;
        c[i] += box[u].w;
        path[i][++path[i][0]] = box[u].id;
        if (dfs(u + 1)) return true;
        path[i][0]--;
        c[i] -= box[u].w;
    }
    return false;
}

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &w[i]);
        box[i] = {i, w[i]};
    }
    scanf("%d %d", &m[1], &m[2]);
    sort(box + 1, box + 1 + n);
    if (!dfs(1)) {
        puts("ERROR");
        return;
    }
    for (int i = 1; i <= 2; ++i) {
        printf("%d���ִ�װ��%d�����ӣ�������Ϊ%d���ֱ���", i, path[i][0], c[i]);
        for (int j = 1; j <= path[i][0]; ++j) {
            printf(" %d��", path[i][j]);
        }
        printf("����\n");
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