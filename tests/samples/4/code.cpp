#include<bits/stdc++.h>
#define ll long long
using namespace std;
const double eps=1e-11;
const int maxn=15005,ha=1e9+7;
inline int add(int x,int y){ x+=y; return x>=ha?x-ha:x;}
inline void ADD(int &x,int y){ x+=y; if(x>=ha) x-=ha;}
int to[maxn][10],k,ans,cnt,a[15],len,hz[maxn];
ll n,num[maxn],f[15][maxn][2],c[maxn];
double b[maxn],L,R,mid;
 
inline void init(){
    for(ll A=1;A<=n;A*=7ll)
        for(ll B=A;B<=n;B*=5ll)
            for(ll C=B;C<=n;C*=3ll)
                for(ll D=C;D<=n;D*=2ll) num[++cnt]=D;
     
    sort(num+1,num+cnt+1);
     
    for(int i=1;i<=cnt;i++){
        to[i][1]=i;
        ll T;
        for(int j=2;j<=9;j++){
            T=num[i]*(ll)j;
            if(T>num[cnt]) break;
            to[i][j]=lower_bound(num+1,num+cnt+1,T)-num;
        }
    }
     
    for(int i=1;i<=9;i++) to[0][i]=i;
}
 
inline void dp(){
    while(n) a[++len]=n%10,n/=10;
    reverse(a+1,a+len+1);
     
    f[0][0][1]=1;
    for(int i=1;i<=len;i++){
         
        f[i][0][0]=f[i-1][0][1]+f[i-1][0][0];
         
        for(int j=0;j<=cnt;j++) if(f[i-1][j][0]||f[i-1][j][1]){
             
            for(int l=1,T;l<=9;l++){
                T=to[j][l];
                if(!T) continue;
                 
                f[i][T][0]+=f[i-1][j][0];
                if(l<a[i]) f[i][T][0]+=f[i-1][j][1];
                else if(l==a[i]) f[i][T][1]+=f[i-1][j][1];
            }
        }
         
    }
     
}
 
inline ll count(){
    ll an=0;
    int l=1;
     
    for(int i=cnt;i;i--){
        while(l<cnt&&b[l]+b[i]+eps<mid) l++;
        if(b[l]+b[i]+eps<mid) break;
        an+=(ll)(cnt-l+1);
    }
     
    return an;
}
 
inline void calc(){
    for(int i=1;i<=cnt;i++) c[i]=f[len][i][0]+f[len][i][1];
    sort(c+1,c+cnt+1);
    for(int i=1;i<=cnt;i++){
        if(c[i]) b[i]=log(c[i]);
        else b[i]=-233;
        R=max(R,b[i]);
    }
     
    L=-233;R*=2;
    while(R-L>=eps){
        mid=(L+R)/2;
        if(count()>=k) L=mid;
        else R=mid;
    }
     
    for(int i=1;i<=cnt;i++) c[i]%=ha;
    for(int i=cnt;i;i--) hz[i]=add(hz[i+1],c[i]);
     
    ll N=0;
    int cj=0,l=1;
     
    for(int i=cnt;i;i--){
        while(l<cnt&&b[l]+b[i]+eps<L) l++;
         
        if(b[l]+b[i]+eps<L) break;
        else if(fabs(b[l]+b[i]-L)<=eps) cj=c[i]*(ll)c[l]%ha;
         
        N+=(ll)(cnt-l+1);
        ADD(ans,c[i]*(ll)hz[l]%ha);
    }
     
    ADD(ans,ha-cj*(ll)(N-k)%ha);
}
 
inline void solve(){
    dp();
    calc();
}
 
int main(){
    scanf("%lld%d",&n,&k),init();
    solve(),printf("%d\n",ans);
     
    return 0;
}