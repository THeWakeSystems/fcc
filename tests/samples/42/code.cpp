#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
using namespace std;
#define debug(x) cout<<"[debug]"#x<<"="<<x<<endl
typedef long long ll;
const int INF=0x3f3f3f3f;
const int N=200005;
ll w[N];
struct Node
{
    int l,r;
    ll d,maxi;
}tr[4*N];
void pushup(Node &res,Node &l,Node &r)
{
    res.maxi=max(l.maxi,r.maxi);
    res.d=__gcd(l.d,r.d);
}
void pushup(int u)
{
    pushup(tr[u],tr[u<<1],tr[u<<1|1]);
}
void build(int u,int l,int r)
{
    if(l==r)
    {
        tr[u]={l,r,w[l],w[l]};
    }
    else
    {
        tr[u]={l,r};
        int mid=l+r>>1;
        build(u<<1,l,mid);
        build(u<<1|1,mid+1,r);

        pushup(u);
    }
}
ll query(int u,int l,int r)
{
    if(tr[u].l>=l&&tr[u].r<=r)
    return tr[u].d;
    else
    {
        int mid=tr[u].l+tr[u].r>>1;
        if(r<=mid) return query(u<<1,l,r);
        else if(l>mid) return query(u<<1|1,l,r);
        else 
        {
            return __gcd(query(u<<1,l,r),query(u<<1|1,l,r));
        }
    }
}
void modify(int u,int l,int r)
{
    if(tr[u].l==tr[u].r)
    {
        ll t=(ll)sqrt(tr[u].maxi);
        tr[u].maxi=t;
        tr[u].d=t;
        return ;
    }                                                                                                                                               
    if(tr[u].l>=l&&tr[u].r<=r)
    {
        if(tr[u].maxi==1)
        return ;

        modify(u<<1,l,r);
        modify(u<<1|1,l,r);

        pushup(u);
        return ;
    }
    int mid=tr[u].l+tr[u].r>>1;
    if(l<=mid) modify(u<<1,l,r);
    if(r>mid) modify(u<<1|1,l,r);

    pushup(u);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    scanf("%lld",&w[i]);

    build(1,1,n);
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int t,l,r;
        scanf("%d%d%d",&t,&l,&r);

        if(t==0)
        {
            modify(1,l,r);
        }
        else
        {
            printf("%lld\n",query(1,l,r));
        }
    }
}