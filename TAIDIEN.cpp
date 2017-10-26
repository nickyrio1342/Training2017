#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i<=b ; i++)
#define FORD(i, a, b) for (int i = a; i>=b; i--)
#define REP(i, a) for (int i = 0; i<a; i++)
#define N 100100
#define pp pair<int, int>
#define IO cin.tie(NULL);cout.tie(NULL);

using namespace std;

vector<int> e[N];
int n, m, f[N];

int root(int u) {
    if (f[u] < 0) return u;
    f[u] = root(f[u]);
    return f[u];
}

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

void solve() {
    int u, v, xx, yy;
    scanf("%d%d%d%d", &n, &m, &xx, &yy);
    FOR(i, 1, n) f[i] = -1;
    REP(i, m) {
        scanf("%d%d", &u, &v);
        int a = root(u);
        int b = root(v);
        if (a != b) Union(a, b);
    }
    if (xx <= yy) {
        printf("%lld\n", 1ll * xx * n);
        return;
    }
    long long ans = 0;
    FOR(i, 1, n) if (f[i] < 0) {
        int t = -f[i] - 1;
        ans += xx + 1ll * t * yy;
    }
    printf("%lld\n", ans);
}

int main() {
    IO;
    freopen("TAIDIEN.inp","r",stdin);
    freopen("TAIDIEN.out","w",stdout);
    n = 0;
    int test;
    scanf("%d", &test);
    while (test--) solve();
}
