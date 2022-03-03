#include <bits/stdc++.h>
#define pii std::pair<int, int>
#define val first
#define idx second
const int inf = 0x3f3f3f3f;

int main()
{
    int n;
    std::cin >> n;
    std::vector<pii> a(n + 1);
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i].val, a[i].idx = i;
    std::sort(a.begin() + 1, a.begin() + n + 1);
    int flag = 0; //0递减，1递增
    int st = 1, max = -inf, min = inf;
    int ans = 0;
    while (st <= n)
    {
        int ed = n;
        for (int j = st; j <= n; ++j)
            if (a[j].val ^ a[st].val)
            {
                ed = j - 1;
                break;
            }
        if (st == 1)
        {
            for (int i = st; i <= ed; ++i)
                min = std::min(min, a[i].idx);
            st = ed + 1;
            continue;
        }
        if (!flag)
        {
            int now = -inf;
            for (int i = st; i <= ed; ++i)
                now = std::max(now, a[i].idx);
            if (now < min)
                for (int i = st; i <= ed; ++i)
                    min = std::min(min, a[i].idx);
            else
                ++ans, flag ^= 1, max = now;
        }
        else
        {
            int now = inf;
            for (int i = st; i <= ed; ++i)
                now = std::min(now, a[i].idx);
            if (now > max)
                for (int i = st; i <= ed; ++i)
                    max = std::max(max, a[i].idx);
            else
                flag ^= 1, min = now;
        }
        st = ed + 1;
    }
    if (!flag)
        ++ans;
    std::cout << ans << std::endl;
    return 0;
}