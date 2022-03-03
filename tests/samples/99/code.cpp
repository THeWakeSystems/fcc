#include <bits/stdc++.h>
#define IOS                           \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(0);                  \
    std::cout.tie(0);
#define pii std::pair<int, int>
#define x first
#define y second

pii a[205];
int cas, n, m, f[25][805], lst[205][25][805], ans[205], ans1, ans2, cnt;

void dfs(int i, int j, int k)
{
    if (j == 0)
        return;
    int now = lst[i][j][k];
    dfs(now - 1, j - 1, k - (a[now].x - a[now].y));
    ans[++cnt] = now, ans1 += a[now].x, ans2 += a[now].y;
}

int main()
{
    IOS;
    while (true)
    {
        ans1 = ans2 = cnt = 0;
        std::cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i].x >> a[i].y;
        memset(f, 0xcf, sizeof(f));
        f[0][400] = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = m; j; --j)
            {
                for (int k = 0; k <= 800; ++k)
                {
                    lst[i][j][k] = lst[i - 1][j][k]; //第i个人不选
                    int val = k - (a[i].x - a[i].y);
                    if (val < 0 || val > 800)
                        continue;
                    if (f[j][k] < f[j - 1][val] + a[i].x + a[i].y)
                        f[j][k] = f[j - 1][val] + a[i].x + a[i].y, lst[i][j][k] = i;
                }
            }
        }
        int max = 0;
        for (int i = 0; i <= 400; ++i)
        {
            if (f[m][400 + i] < 0 && f[m][400 - i] < 0)
                continue;
            if (f[m][400 + i] > f[m][400 - i])
            {
                max = 400 + i;
                break;
            }
            else
            {
                max = 400 - i;
                break;
            }
        }
        dfs(n, m, max);
        std::cout << "Jury #" << ++cas << std::endl;
        std::cout << "Best jury has value " << ans1 << " for prosecution and value " << ans2 << " for defence:" << std::endl;
        for (int i = 1; i <= cnt; ++i)
            std::cout << " " << ans[i];
        std::cout << std::endl
                  << std::endl;
    }
    return 0;
}