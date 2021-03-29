#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
const int N = 1e4 + 7;

int a[N], n, x;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + 1 + n);
    scanf("%d", &x);
    int l = 1, r = n, mid;
	while (l <= r) {
	    mid = l + r >> 1; 
	    if (a[mid] == x) break;
	    if (a[mid] < x) {
	        l = mid + 1;
	    } else {
	        r = mid - 1;
	    }
	}
    if (a[mid] == x) {
        printf("%d\n", mid);
    } else {
        puts("0");
    }
    return 0;
}
