#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i<=b ; i++)
#define FORD(i, a, b) for (int i = a; i>=b; i--)
#define REP(i, a) for (int i = 0; i<a; i++)
#define N 1001
#define pp pair<int, int>
#define IO  cin.tie(NULL);cout.tie(NULL);

using namespace std;

int n, m, a[N][N];
int dd[N][N], num[N * N], cnt;
bool fired[N * N];

bool inside(int i, int j) {
    return i>0&&i<=m&&j>0&&j<=n;
}
queue<pp> q;
const int d[4] = {0, 1, 0, -1};
const int c[4] = {1, 0, -1, 0};

void bfs(int ii, int jj) {
    q.push(pp(ii, jj));
    num[cnt] = 0;
    dd[ii][jj] = cnt;
    while (!q.empty()) {
        int u = q.front().first;
        int v = q.front().second;
        q.pop();
        num[cnt]++;
        REP(i, 4) {
            int uu = u + d[i];
            int vv = v + c[i];
            if (inside(uu, vv) && !dd[uu][vv] && a[uu][vv]) {
                dd[uu][vv] = cnt;
                q.push(pp(uu, vv));
            }
        }
    }
}
int main() {
    freopen("HOACONG.inp","r",stdin);
    freopen("HOACONG.out","w",stdout);
    IO;
    int q;
    scanf("%d%d%d", &m, &n, &q);
    FOR(i, 1, m) FOR(j, 1, n) scanf("%d", &a[i][j]);
    memset(dd, 0, sizeof dd);
    cnt = 0;
    int now = 0;
    FOR(i, 1, m) FOR(j, 1, n) if (!dd[i][j] && a[i][j]) {
        ++cnt;
        bfs(i, j);
        now += num[cnt];
    }
    int x, y;
    memset(fired, false ,sizeof fired);

    while (q--) {
        scanf("%d%d", &x, &y);
        if (a[x][y] && !fired[dd[x][y]]) {
            fired[dd[x][y]] = true;
            now -= num[dd[x][y]];
        }
        printf("%d\n", now);
    }
}
