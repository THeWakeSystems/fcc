#include <cstdio>
#include <iostream>
using namespace std;
const int N = 50005, L = 63;
typedef long long LL;
int n, m;
bool vis[N];
LL a[N], d[L];
struct E{
    int next, v;
    LL w;
} e[N << 2];
int head[N], numE = 0;
inline void add(int u, int v, LL w) {
    e[++numE] = (E) { head[u], v, w };
    head[u] = numE;
}
void insert(LL val) {
    for (int i = L - 1; ~i; i--) {
        if (val >> i & 1) {
            if(d[i]) val ^= d[i];
            else { d[i] = val; break; }    
        }
    }
}
void dfs(int u) {
    vis[u] = true;
    for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].v;
        if(!vis[v]) a[v] = a[u] ^ e[i].w, dfs(v);
        else insert(a[u] ^ a[v] ^ e[i].w);
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1, u, v; i <= m; i++) {
        LL w;
        scanf("%d%d%lld", &u, &v, &w), add(u, v, w), add(v, u, w);
    }
    dfs(1);
    LL ans = a[n];
    for (int i = L - 1; ~i; i--)
        if((ans ^ d[i]) > ans) ans ^= d[i];
    printf("%lld\n", ans);
}
