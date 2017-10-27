#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i<=b ; i++)
#define FORD(i, a, b) for (int i = a; i>=b; i--)
#define REP(i, a) for (int i = 0; i<a; i++)
#define N 1001000
#define pp pair<int, int>
#define IO cin.tie(NULL);cout.tie(NULL);


template<typename T> inline void read(T &x) {
    char c;
    while (!isdigit(c = getchar()));
    x = 0;
    do {
        x = x * 10 + c - '0';
    } while (isdigit(c = getchar()));
}

template<typename T> inline void write(T x) {
    if (x < 10) {
        putchar(char(x + 48));
    }
    else {
        write(x/10);
        putchar(char(48 + x%10));
    }
}

template<typename T> inline void writeln(T x) {
    write(x);
    putchar('\n');
}

using namespace std;

int n, m, u, v, f[N];

int root(int u) {
    if (f[u] < 0) return u;
    return f[u] = root(f[u]);
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

int main() {
    freopen("DSF.inp","r",stdin);
    freopen("DSF.out","w",stdout);
    IO;
    read(n);read(m);
    int cnt = n;
    FOR(i, 1, n) f[i] = -1;
    REP(i, m) {
        read(u);read(v);
        int a = root(u);
        int b = root(v);
        if (a != b) {
            Union(a, b);
            cnt--;
        }
        writeln(cnt);
    }
}
