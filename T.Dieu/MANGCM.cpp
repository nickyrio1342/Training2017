#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i<=b ; i++)
#define FORD(i, a, b) for (int i = a; i>=b; i--)
#define REP(i, a) for (int i = 0; i<a; i++)
#define N 100100
#define pp pair<int, int>
#define IO  cin.tie(NULL);cout.tie(NULL);

using namespace std;

int n, d[N], p[N];
bool f[N];
vector<int> e[N];

void dfs(int u) {
    for (int v : e[u]) {
        if (v == p[u]) continue;
        d[v] = d[u] + 1;
        p[v] = u;
        dfs(v);
    }
}

void trace(int u) {
    f[u] = true;
    if (p[u] != -1) trace(p[u]);
}

void solve() {
    FOR(i, 1, n) e[i].clear();
    scanf("%d", &n);
    int u, v;
    REP(i, n - 1) {
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    FOR(i, 1, n) p[i] = 0;
    p[1] = -1;
    d[1] = 1;
    dfs(1);
    int mx = 1;
    FOR(i, 1, n) if (d[i] > d[mx]) mx = i;
    FOR(i, 1, n) p[i] = 0;
    p[mx] = -1;
    d[mx] = 1;
    dfs(mx);
    mx = 1;
    memset(f, false ,sizeof f);
    FOR(i, 1, n) if (d[i] > d[mx]) mx = i;
    trace(mx);
    FOR(i, 1, n) {
        if (f[i]) continue;
        if (p[i] == -1 || f[p[i]]) continue;
        printf("NO\n");
        return;
    }
    printf("YES\n");
}
int main() {
    IO;
    freopen("MANGCM.inp","r",stdin);
    freopen("MANGCM.out","w",stdout);
    int test;
    scanf("%d", &test);
    while (test--) solve();
}
