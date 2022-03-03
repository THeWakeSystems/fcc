#pragma GCC Optimize(3)
#pragma GCC Optimize(2)
#include <bits/stdc++.h>
using namespace std;
//#define ACM_LOCAL
const int N = 2e6 + 10;
const int mod = 1e9 + 7;
using ll = long long;
int f[1<<16], g[1<<16];
int n, m, a[20], num[1<<16];
int get(int x) {
    int ans = 0;
    for (int i = 0; i < n; i++) if (x>>i&1) ans++;
    return ans;
}
void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n, greater<int>());
    for (int i = 0; i < m; i++) {
        int nn; cin >> nn;
        int state=0;
        for (int j = 1; j <= nn; j++) {
            int x; cin >> x;
            state|=(1<<(x-1));
        }
        g[state]=1;
    }
    for (int i = 1; i < 1 << n; i++) num[i]=get(i);
    for (int i = 1; i < 1 << n; i++) {
        if (g[i]) f[i]=max(f[i], a[num[i]-1]);
        for (int j = i; j; j = (j - 1) & i) {
            int tmp=i^j;
            if (!g[tmp]) continue;
            f[i]=max(f[i],f[j]+a[num[i]-1]);
        }
        for (int j = 0; j < n; j++) f[i|(1<<j)]=max(f[i|(1<<j)], f[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) ans += a[i];
    cout << ans - f[(1<<n)-1] << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
#ifdef ACM_LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
#ifdef ACM_LOCAL
    auto st = clock();
#endif
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
#ifdef ACM_LOCAL
    auto ed = clock();
    cerr << "Run time: "  << double(ed-st)/CLOCKS_PER_SEC << "s" << endl;
#endif
    return 0;
}