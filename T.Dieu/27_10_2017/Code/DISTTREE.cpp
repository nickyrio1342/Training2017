#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i<=b ; i++)
#define FORD(i, a, b) for (int i = a; i>=b; i--)
#define REP(i, a) for (int i = 0; i<a; i++)
#define N 100100
#define pp pair<int, int>
#define IO ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);

using namespace std;

int n, k, u, v;
long long ans, f[N][555], tmp[555];
vector<int> e[N];

void dfs(int u, int p) {
    f[u][0] = 1;
    for (int v : e[u]) if (v != p) {
        dfs(v, u);
        FOR(i, 1, k) {
            tmp[i] = f[v][i - 1];
            ans += tmp[i] * f[u][k - i];
        }
        FOR(i, 1, k) f[u][i] += tmp[i];
    }
}
int main() {
    IO;
    cin>>n>>k;
    REP(i, n - 1) {
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    memset(f, 0, sizeof f);
    ans = 0;
    dfs(1, -1);
    cout<<ans;
}
