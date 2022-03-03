#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 20;
int a[maxn][maxn], b[maxn], sum[maxn];
int dp[1 << maxn];

int main() {
    int t;scanf("%d", &t);
    while (t--) {
        int n, m, x, y;
        scanf("%d %d", &n, &m);
        memset(a, 0, sizeof(a));
        memset(sum, 0, sizeof(sum));
        memset(dp, 0x3f, sizeof (int) * (1 << m));

        for (int i = 1; i <= n; ++i) {
            scanf("%d %d", &x, &y);
            a[--x][--y]++;
            sum[x]++;
        }
        dp[0] = 0;
        for (int s = 0; s < (1 << m); ++s) {
            memset(b, 0, sizeof(b));
            for (int i = 0; i < m; ++i) {
                if (s & (1 << i)) {
                    for (int j = 0; j < m; ++j) {
                        b[j] += a[i][j];
                    }
                    
                }
            }

            for (int i = 0; i< m; ++i) {
                if ((s & (1 << i)) == 0) {
                    int cost = (sum[i] == a[i][i] ? 0 : sum[i] + b[i]);
                    dp[s | (1 << i)] = min(dp[s | (1 << i)], dp[s] + cost);
                }
            }
        }
        cout << dp[(1 << m) - 1] << endl;
    }
}