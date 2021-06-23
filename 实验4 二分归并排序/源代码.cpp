#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;

int a[N], tmp[N];
int n;

void binaryMerge(int l, int r) {
    if (l == r) return;
    int mid = l + r >> 1;
    binaryMerge(l, mid);
    binaryMerge(mid + 1, r);
    int p1 = l, p2 = mid + 1, tot = l;
    while (p1 <= mid || p2 <= r) {
        if (p1 > mid || (p2 <= r && a[p1] > a[p2])) tmp[tot++] = a[p2++];
        else tmp[tot++] = a[p1++];
    }
    for (int i = l; i <= r; ++i) a[i] = tmp[i];
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    binaryMerge(1, n);
    for (int i = 1; i <= n; ++i) {
        printf("%d%c", a[i], " \n"[i == n]);
    }
    return 0;
}
