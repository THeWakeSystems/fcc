#include<bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3fll
typedef unsigned long long ull;
typedef long long ll;
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define nep(i,r,l) for(int i=r;i>=l;i--)
void sc(int &x){scanf("%d",&x);}
void sc(int &x,int &y){scanf("%d%d",&x,&y);}
void sc(int &x,int &y,int &z){scanf("%d%d%d",&x,&y,&z);}
void sc(ll &x){scanf("%lld",&x);}
void sc(ll &x,ll &y){scanf("%lld%lld",&x,&y);}
void sc(ll &x,ll &y,ll &z){scanf("%lld%lld%lld",&x,&y,&z);}
void sc(char *x){scanf("%s",x);}
void sc(char *x,char *y){scanf("%s%s",x,y);}
void sc(char *x,char *y,char *z){scanf("%s%s%s",x,y,z);}
void out(int x){printf("%d\n",x);}
void out(ll x){printf("%lld\n",x);}
void out(int x,int y){printf("%d %d\n",x,y);}
void out(ll x,ll y){printf("%lld %lld\n",x,y);}
void out(int x,int y,int z){printf("%d %d %d\n",x,y,z);}
void out(ll x,ll y,ll z){printf("%lld %lld %lld\n",x,y,z);}
using namespace std;
const int N=1e5+5;
int n,m,tot,a[N],hs[N],b[N],c[N],d[N];
ll t1[N<<2],t2[N<<2];
void Insert(int l,int r,int k,int x,ll v,ll t[N<<2])
{
    t[k]=min(t[k],v);
    if(l==r) return;
    int m=l+r>>1;
    if(x<=m) Insert(l,m,k<<1,x,v,t);
    else Insert(m+1,r,k<<1|1,x,v,t);
}
ll query(int l,int r,int k,int x,int y,ll t[N<<2])
{
    if(r<x||l>y) return inf;
    if(l>=x&&r<=y) return t[k];
    int m=l+r>>1;
    return min(query(l,m,k<<1,x,y,t),query(m+1,r,k<<1|1,x,y,t));
}
int main()
{
    sc(n,m);
    rep(i,1,n)
        sc(a[i],b[i],c[i]),sc(d[i]),hs[++tot]=c[i];
    hs[++tot]=1;hs[++tot]=m;
    m=tot;
    sort(hs+1,hs+1+m);
    m=unique(hs+1,hs+1+m)-hs-1;
    rep(i,1,n)
    {
        a[i]=lower_bound(hs+1,hs+1+m,a[i])-hs;
        b[i]=upper_bound(hs+1,hs+1+m,b[i])-hs-1;
        c[i]=lower_bound(hs+1,hs+1+m,c[i])-hs;
    }
    memset(t1,inf,sizeof(t1));
    memset(t2,inf,sizeof(t2));
    Insert(1,m,1,1,0,t1);
    Insert(1,m,1,m,0,t2);
    ll ans=inf;
    rep(i,1,n)
    {
        ll s1=query(1,m,1,a[i],b[i],t1),s2=query(1,m,1,a[i],b[i],t2);
        ans=min(ans,s1+s2+d[i]);
        Insert(1,m,1,c[i],s1+d[i],t1);
        Insert(1,m,1,c[i],s2+d[i],t2);
    }
    if(ans==inf) ans=-1;
    out(ans);
}
