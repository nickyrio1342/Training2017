#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i<=b ; i++)
#define FORD(i, a, b) for (int i = a; i>=b; i--)
#define REP(i, a) for (int i = 0; i<a; i++)
#define N 1001
#define pp pair<int, int>
#define IO cin.tie(NULL);cout.tie(NULL);

using namespace std;

int m, n, a[N][N], d[N][N];
bool fr[N][N];
const int inf = 1e9;
queue<pp> q;

const int dd[4] = {0, 1, 0, -1};
const int cc[4] = {1, 0, -1, 0};

bool inside(int i, int j) {
    return i>0 && i<=m && j>0 && j<=n;
}

void bfs() {
    while (!q.empty()) {
        int u = q.front().first;
        int v = q.front().second;
        q.pop();
        REP(i, 4) {
            int uu = u + dd[i];
            int vv = v + cc[i];
            if (inside(uu, vv) && a[uu][vv] == 1 && fr[uu][vv]) {
                fr[uu][vv] = false;
                d[uu][vv] = d[u][v] + 1;
                q.push(pp(uu, vv));
            }
        }
    }
}
int main() {
    IO;
    freopen("BDBANGSO.inp","r",stdin);
    freopen("BDBANGSO.out","w",stdout);
    scanf("%d %d", &m, &n);
    memset(fr, true, sizeof fr);
    FOR(i, 1, m) FOR(j, 1, n) d[i][j] = inf;
    FOR(i, 1, m) FOR(j, 1, n) {
        read(a[i][j]);
        if (a[i][j] == 2) {
            q.push(pp(i, j));
            d[i][j] = 0;
        }
    }
    bfs();
    int ans = 0;
    FOR(i, 1, m) FOR(j, 1, n) if (a[i][j] == 1) {
        if (d[i][j] == inf) {
            write(-1);
            return 0;
        } else ans = max(ans, d[i][j]);
    }
    printf("%d", ans);
}
