#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
ll mod=2004;
ll n,a,b;
ll m[20];
ll fx(ll x){//要求的是C(n,n+x)%mod的值 
    ll sum=1;
    for(int i=1;i<=n;i++){
        sum=sum*(x+i)%mod;
    }
    return sum;
}
ll f(ll x){
    if(x==-1) return 0;
    ll sum=0;
    for(int i=0;i<(1<<n);i++){
        ll flag=1,re=0;
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                re+=m[j];
                flag=-flag;
            }
        }
        if(x-re>=0) sum=(sum+(flag*(fx(x-re))+mod)%mod)%mod;
    }
    return sum;
}
int main(){
    scanf("%lld%lld%lld",&n,&a,&b);
    for(int i=0;i<n;i++){
        scanf("%lld",&m[i]);
        m[i]++;
    }
    ll ss=1;
    for(int i=1;i<=n;i++){
        ss*=i;
    }
    mod*=ss;
    ll sum1=f(b),sum2=f(a-1);
    sum1/=ss,sum2/=ss;
    mod/=ss;
    printf("%lld",(sum1-sum2+mod)%mod);
    return 0;
}