#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i<=b ; i++)
#define FORD(i, a, b) for (int i = a; i>=b; i--)
#define REP(i, a) for (int i = 0; i<a; i++)
#define N 100100
#define pp pair<int, int>
#define IO cin.tie(NULL);cout.tie(NULL);

using namespace std;

int n, q, p[N], b[N][30], level[N], LOG;
vector<int> e[N];

void dfs(int u) {
    for (int v : e[u]) {
        if (v != p[u]) {
            level[v] = level[u] + 1;
            p[v] = u;
            dfs(v);
        }
    }
}

void buildLCA() {
    LOG = log2(n);
    p[1] = 0;
    FOR(i, 0, n) b[i][0] = p[i];
    FOR(j, 1, LOG) FOR(i, 0, n) b[i][j] = b[b[i][j - 1]][j - 1];
}
#define bit(S, i) (S >> i) & 1

void Up(int &u, int d) {
    FORD(i, LOG, 0) {
        if (bit(d, i)) u = b[u][i];
    }
}

int LCA(int u, int v) {
    if (level[u] > level[v]) Up(u, level[u] - level[v]);
    if (level[u] < level[v]) Up(v, level[v] - level[u]);
    if (u == v) return u;
    int res;
    FORD(i, LOG, 0) {
        if (b[u][i] != b[v][i]) {
            u = b[u][i];
            v = b[v][i];
        } else res = b[u][i];
    }
    return res;
}
int main() {
    freopen("LCA.inp","r",stdin);
    freopen("LCA.out","w",stdout);
    IO;
    scanf("%d", &n);
    int u, v;
    REP(i, n - 1) {
        scanf("%d %d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    p[1] = -1;
    level[1] = 1;
    dfs(1);
    scanf("%d", &q);
    buildLCA();
    while (q--) {
        scanf("%d %d", &u, &v);
        printf("%d\n", LCA(u, v));
    }
}
