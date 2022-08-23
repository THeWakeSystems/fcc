#include<bits/stdc++.h>
#include <sys/time.h> 
using namespace std;
#define ll long long
#define N 100003
struct node
{
    string s;
    ll num;
}a[N];
ll n,m;
ll check(ll loc,ll cnt)
{
    for(ll i=1;i<=n;i++)
    {
        if(a[i].s=="OR")
            cnt|=(a[i].num>>loc);
        else if(a[i].s=="XOR")
            cnt^=(a[i].num>>loc);
        else
            cnt&=(a[i].num>>loc);
    }
    return cnt;
}
int main()
{
//	freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
        cin>>a[i].s>>a[i].num;
    struct timeval start;
    struct timeval end;
    float time_use=0;
    gettimeofday( &start, NULL );
    ll res=0,ans=0;
    for(ll i=29;i>=0;i--)
    {
        ll k0=check(i,0),k1=check(i,1);
        if(ans+(1<<i)<=m)
        {
            if(k0<k1)
            {
                res|=(k1<<i);
                ans+=(1<<i);
            }
            else
                res|=(k0<<i);
        }
        else
            res|=(k0<<i);
    }
    gettimeofday( &end, NULL );
    time_use=(end.tv_sec-start.tv_sec)*1000000+(end.tv_usec-start.tv_usec);//微秒
    
    cout<<res<<endl;
    printf("time_use is %f\n",time_use);
    return 0;
}
