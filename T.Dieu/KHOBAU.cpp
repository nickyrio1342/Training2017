#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i<=b ; i++)
#define FORD(i, a, b) for (int i = a; i>=b; i--)
#define REP(i, a) for (int i = 0; i<a; i++)
#define N 1001
#define pp pair<int, int>
#define IO ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);

using namespace std;

int m, n, ans;
string s[N];
bool canReach[N][N];

bool inside(int i, int j) {
    return i>=0 && i<m && j>=0 && j<n;
}

const int d[4] = {0, 1, 0, -1};
const int c[4] = {1, 0, -1, 0};

void dfs(int u, int v) {
    canReach[u][v] = true;
    if (s[u][v] == 'G') ans++;
    REP(i, 4) {
        if (inside(u + d[i], v + c[i]) && s[u + d[i]][v + c[i]] == 'T') return;
    }
    REP(i, 4) {
        int uu = u + d[i];
        int vv = v + c[i];
        if (inside(uu, vv) && s[uu][vv] != '#' && !canReach[uu][vv]) {
            dfs(uu, vv);
        }
    }
}
int main() {
    freopen("KHOBAU.inp","r",stdin);
    freopen("KHOBAU.out","w",stdout);
    IO;
    cin>>n>>m;
    REP(i, m) cin>>s[i];
    int sx, sy;
    REP(i, m) REP(j, n) if (s[i][j] == 'P') {sx = i; sy = j;}
    memset(canReach, false, sizeof canReach);
    ans = 0;
    dfs(sx, sy);
    cout<<ans;
}
