#include <bits/stdc++.h>
#define IOS                           \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(0);                  \
    std::cout.tie(0);
using ull = unsigned long long;
const int maxn = 1e6 + 5;

std::string s;
ull f1[maxn], p1[maxn], f2[maxn], p2[maxn];

int solve()
{
    int ans = 0;
    int n = s.length();
    p1[0] = 1, p2[0] = 1;
    for (int i = 1; i <= n; ++i)
        p1[i] = p1[i - 1] * 99991;
    for (int i = 1; i <= n; ++i)
        f1[i] = f1[i - 1] * 99991 + (s[i - 1] - 'a' + 1);
    std::reverse(s.begin(), s.end());
    for (int i = 1; i <= n; ++i)
        p2[i] = p2[i - 1] * 99991;
    for (int i = 1; i <= n; ++i)
        f2[i] = f2[i - 1] * 99991 + (s[i - 1] - 'a' + 1);
    std::reverse(s.begin(), s.end());
    for (int i = 1; i <= n; ++i)
    {
        int l = 0, r = std::min(i - 1, n - i), max = 0;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (f1[i - 1] - f1[i - mid - 1] * p1[mid] == f2[n - i] - f2[n - i - mid] * p2[mid])
                l = mid + 1, max = mid;
            else
                r = mid - 1;
        }
        ans = std::max(ans, 2 * max + 1);
    }
    for (int i = 1; i <= n; ++i)
    {
        int l = 0, r = std::min(i - 1, n - i + 1), max = 0;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (f1[i - 1] - f1[i - mid - 1] * p1[mid] == f2[n - i + 1] - f2[n - i - mid + 1] * p2[mid])
                l = mid + 1, max = mid;
            else
                r = mid - 1;
        }
        ans = std::max(ans, 2 * max);
    }
    return ans;
}

int main()
{
    IOS;
    int cas = 0;
    while (true)
    {
        std::cin >> s;
        if (s == "END")
            break;
        std::cout << "Case " << ++cas << ": " << solve() << std::endl;
    }
    return 0;
}