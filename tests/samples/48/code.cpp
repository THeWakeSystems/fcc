#include<bits/stdc++.h>
typedef long long ll;
const int MAX = 1e7 + 10;

ll make(ll n)
{
    if(n == 0) return 0;
    ll x = (n - 1)/ 192;
    return 192 * (0 + x) * (x + 1) / 2 + x + 1;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int t;
    std::cin >> t;
    while(t--)
    {
        ll l, r;
        std::cin >> l >> r;
        std::cout << make(r) - make(l - 1) << std::endl;
    }
}
