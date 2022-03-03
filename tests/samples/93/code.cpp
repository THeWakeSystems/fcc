#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=10005;
int a[N];
int a2[N];
int n,ans;
const int mod=1e9+7;
inline int ksm(int x,int y)
{
    int ans=1;
    for (;y;y/=2,x=(ll)x*x%mod)
        if (y&1)
            ans=(ll)ans*x%mod;
    return ans;
}
int main()
{
    while (~scanf("%d",&n))
    {
        for (int i=1;i<=n;++i)
            scanf("%d",&a[i]);
        for (int i=1;i<=n;++i)
            a2[i]=(ll)a[i]*a[i]%mod;
        ans=0;
        for (int i=1;i<=n;++i)
        {
            int sum=1;
            for (int j=1;j<=n;++j)
                if (i!=j)
                    sum=(ll)sum*((a2[j]-a2[i]+mod)%mod)%mod;
            //cout<<i<<' '<<sum<<endl;
            (ans+=ksm((ll)sum*a[i]%mod,mod-2))%=mod;
        }
        ans=(ll)ans*ksm(2,mod-2)%mod;
        printf("%d\n",ans);
    }
    return 0;
}
