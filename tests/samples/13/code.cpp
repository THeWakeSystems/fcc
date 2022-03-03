#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e6 + 10;
 
int n;
long long f[N], g[N], a[N], m;
 
int check(long long x)
{
    f[1] = g[1] = m;
    for(int i = 2; i <= n; i++)
    {
        if(m - f[i - 1] >= a[i])g[i] = m;
        else
        {
            g[i] = m - a[i] + m - f[i - 1];
        }
        if(x - m - (m - g[i - 1]) >= a[i])f[i] = max(0ll, m - (x - m));
        else
        {
            f[i] = a[i] - (x - m - (m - g[i - 1]));
        }
    }
    if(m - f[n] >= a[1])return 1;
    return 0;
}
 
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%lld", &n, &m);
        long long mx = 0;
        for(int i = 1; i <= n; i++)
            scanf("%lld", &a[i]), mx = max(mx, a[i]);
        if(mx > m)
        {
            puts("-1");
            continue;
        }
        long long l = m + mx, r = m + 2 * mx, ans = 0;
        while(l <= r)
        {
            long long mid = (l + r) >> 1;
            if(check(mid))r = mid - 1, ans = mid;
            else l = mid + 1;
        }
        printf("%lld\n", ans);
    }
}