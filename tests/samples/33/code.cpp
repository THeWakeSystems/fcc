#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const double pi=acos(-1);
const int inf=1e9;
#define linf 0x3f3f3f3f3f3f3f3f
#define lson  p<<1
#define rson  p<<1|1
#define pb  push_back
#define pii pair<int,int>
#define pII pair<int,pii>
#define pll pair<ll,ll>
#define se second
#define fi first
/*    */
const int maxn=5e5+15;

struct node{
    int nxt,to;
}edge[maxn<<1];
int head[maxn];
int tot;
void add(int x,int y){
    edge[++tot].to=y;
    edge[tot].nxt=head[x];head[x]=tot;
}
int z[maxn];
ll dp[maxn];
int cnt;
int k;
void dfs(int x,int fa,ll mid){
    dp[x]=z[x];
    for(int i=head[x];i;i=edge[i].nxt){
        int y=edge[i].to;
        if(y==fa) continue;
        dfs(y,x,mid);
        if(dp[y]>=mid) cnt++;
        else dp[x]+=dp[y];
    }
}
int n;
bool check(ll mid){
    cnt=0;
    for(int i=1;n>=i;i++) dp[i]=0;
    dfs(1,0,mid);
    if(dp[1]>=mid) cnt++;
    return cnt>=k;
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;n>i;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b);
        add(b,a);
    }
    for(int i=1;n>=i;i++){
        scanf("%d",&z[i]);
    }
    ll l=0,r=1e10;
    while(l<=r){
        ll mid=(l+r)>>1;
        if(check(mid)) l=mid+1;
        else r=mid-1;
    }
    printf("%lld\n",r);
    return 0;
}
