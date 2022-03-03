#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,b,p,ans;
signed main()
{
    cin >> a >> b >> p;
    ans=1%p;
    for(;b;b>>=1)
    {
        if (b&1)
            ans=ans*a%p;
        a=a*a%p;
    }
    cout << ans;
    return 0;
}