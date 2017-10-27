#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i<=b ; i++)
#define FORD(i, a, b) for (int i = a; i>=b; i--)
#define REP(i, a) for (int i = 0; i<a; i++)
#define N 100100
#define pp pair<int, int>
#define IO cin.tie(NULL);cout.tie(NULL);

using namespace std;

queue<int> q;
int n, a, b, u, v, t[N], trace[N];
bool fr[N];
vector<int> e[N];

bool bfs(int mid) {
    while (!q.empty()) q.pop();
    q.push(a);
    memset(fr, true, sizeof fr);
    fr[a] = false;
    trace[a] = -1;
    while (!q.empty() && fr[b]) {
        int u = q.front();
        q.pop();
        for (int v : e[u]) if (fr[v]){
            if (abs(t[u] - t[v]) <= mid) {
                fr[v] = false;
                trace[v] = u;
                q.push(v);
            }
        }
    }
    return !fr[b];
}

void go(int u) {
    if (trace[u] != -1) go(trace[u]);
    printf("%d ", u);
}

int main() {
    IO;
    freopen("MOVE.inp","r",stdin);
    freopen("MOVE.out","w",stdout);
    scanf("%d%d%d", &n, &a, &b);
    FOR(i, 1, n) scanf("%d", &t[i]);
    while (scanf("%d %d", &u, &v) != EOF) {
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int cur = -1;
    int l = 0;
    int r = 2e4;
    while (l <= r) {
        int m = (l + r) >> 1;
        if (bfs(m)) {
            cur = m;
            r = m - 1;
        } else l = m + 1;
    }
    printf("%d\n", cur);
    if (cur != -1) {
        bfs(cur);
        go(b);
    }
}
