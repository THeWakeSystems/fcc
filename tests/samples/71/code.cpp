//  . ∧---∧
// （〃￣∇￣）
// Keep Moving ~
#include <bits/stdc++.h>
#define CLEAR(a,val) memset(a, val, sizeof (a))
#define FOR(i,a,b)   for(int i=(a); i<int(b); ++i)
#define FORE(i,a,b)  for(int i=(a); i<=int(b); ++i)
#define FORD(i,a,b)  for(int i=int(a); i>=b; --i)
#define FORA(i,a)    for(auto& i: a)
#define SZ(a)        int(a.size())
#define ALL(a)       (a).begin(),(a).end()
#define DV1(t, a, n, val) vector<t> a(n, val)
#define DV2(t, a, n, m, val) vector<vector<t>> a(n, vector<t>(m, val))
template<typename T> inline T gcd(T a, T b) { return b == 0 ? a : gcd(b, a % b); }

#ifdef LOCAL_LOGGER
    #include "contests/logger.h"
    #define log(...) Logger::log(#__VA_ARGS__, __VA_ARGS__);
    template<typename T> void vout(std::vector<T>& v) { 
        FOR(i, 0, SZ(v)) std::cout << v[i] << " \n"[i == SZ(v) - 1];
    }
#else
    #define log(...)
    template<typename T> void vout(std::vector<T>& v) { }
#endif

using namespace std;
using ll = long long;
using PII = pair<int, int>;


void run_test_case() {
    int n;
    cin >> n;
    vector<PII> v(2 * n);
    cin >> v[0].first;
    FOR(i, 1, n) {
        cin >> v[i].first;
        v[i - 1].second = v[i].first;
    }
    v[n - 1].second = v[0].first;
    FOR(i, n, 2 * n) {
        v[i] = v[i - n];
    }
    // dp[i, j] = max{ dp[i][k] + dp[k + 1][j] + v[i].first * v[k].second * v[j].second }
    DV2(int, dp, 2 * n, 2 * n, 0);
    FORE(len, 2, n) {
        FOR(i, 0, 2 * n) {
            int j = i + len - 1;
            if (j >= 2 * n) continue;
            FOR(k, i, j) {
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j] + v[i].first * v[k].second * v[j].second);
            }
        }
    }
    int ans = 0;
    FOR(i, 0, n) {
        int j = i + n - 1;
        ans = max(ans, dp[i][j]);
    }
    cout << ans << endl;

}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
    bool read_t = false;
#ifdef LOCAL_DATA
#include "contests/runner.h"
#else
    if (read_t) { cin >> t; }
    // if (read_t) { scanf("%d", &t); }
    while(t--) { run_test_case(); }
#endif
    return 0;
}
