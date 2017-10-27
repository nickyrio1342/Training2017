#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i<=b ; i++)
#define FORD(i, a, b) for (int i = a; i>=b; i--)
#define REP(i, a) for (int i = 0; i<a; i++)
#define N 1001000
#define pp pair<int, int>
#define IO ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);

using namespace std;

string st;

queue<int> q;
vector<int> e[10];
int a[10][10], f[N];
bool fr[10];

void bfs(int start) {
    q.push(start);
    REP(i, st.size()) f[i] = -1;
    f[start] = 0;
    memset(fr, true, sizeof fr);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (fr[st[u] - '0']) {
            for (int v : e[st[u] - '0']) {
                if (f[v] == -1) {
                    f[v] = f[u] + 1;
                    q.push(v);
                }
            }
            fr[st[u] - '0'] = false;
        }
        if (u && f[u - 1] == -1) {
            f[u - 1] = f[u] + 1;
            q.push(u - 1);
        }
        if (u != st.size() - 1 && f[u + 1] == -1) {
            f[u + 1] = f[u] + 1;
            q.push(u + 1);
        }
    }
}

int main() {
    freopen("DIGJUMP.inp","r",stdin);
    freopen("DIGJUMP.out","w",stdout);
    IO;
    cin>>st;
    REP(i, st.size()) {
        e[st[i] - '0'].push_back(i);
    }
    bfs(0);
    cout<<f[st.size() - 1];
}
