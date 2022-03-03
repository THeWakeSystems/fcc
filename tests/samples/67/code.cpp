#include<iostream>
using namespace std;
typedef long long ll;
ll exgcd(ll a,ll b,ll &x,ll&y)
{
    if(!b)
    {
        x=1;y=0;return a;
    }
    ll d=exgcd(b,a%b,y,x);
    y=y-a/b*x;
    return d;
}
ll gcd(ll a,ll b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int  main()
{
    ll a,b,c,x,y,d,n;
    int t;
    cin>>t;
    while(t--)
    {
        ll m,l,r;
        cin>>n>>d>>x>>y;
        m=(y-x+n)%n;
        ll g=exgcd(d,n,l,r);
        if(m%g)
        {
            puts("Impossible");
            continue;
        }
        n=n/g;
        d=d/g;
        l=l*m/g;
        l=(l%n+n)%n;
        cout<<l<<endl;

    }
    return 0;
}