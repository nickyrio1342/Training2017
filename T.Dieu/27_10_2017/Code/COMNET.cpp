#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i<=b ; i++)
#define FORD(i, a, b) for (int i = a; i>=b; i--)
#define REP(i, a) for (int i = 0; i<a; i++)
#define N 1001000
#define pp pair<int, int>
#define IO cin.tie(NULL);cout.tie(NULL);

using namespace std;

int n, m, u, v, f[N];

void Union(int a, int b) {
    int t = f[a] + f[b];
    if (f[a] <= f[b]) {
        f[a] = t;
        f[b] = a;
        return;
    }
    f[a] = b;
    f[b] = t;
}

int root(int u) {
    if (f[u] < 0) return u;
    f[u] = root(f[u]);
    return f[u];
}

int main() {
    freopen("COMNET.inp","r",stdin);
    freopen("COMNET.out","w",stdout);
    IO;
    scanf("%d %d", &n, &m);
    FOR(i, 1, n) f[i] = -1;
    FOR(i, 1, m) {
        scanf("%d %d", &u, &v);
        int a = root(u);
        int b = root(v);
        if (a != b) Union(a, b);
        if (root(1) == root(n)) {
            printf("%d", i);
            return 0;
        }
    }
    printf("-1");
}
