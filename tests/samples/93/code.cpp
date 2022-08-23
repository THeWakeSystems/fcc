#include<bits/stdc++.h>
using namespace std;
long long a[100001]={1},num[100001],l[100001],v[100001],t,mod=1000000009;
long long pow(long long x,long long k){
    long long ans=1%mod;
    for(;k;k>>=1){if(k&1) ans=ans*x%mod;x=(long long)x*x%mod;}
    return ans%mod;
}
int main(){
    for(int i=1;i<=100000;i++)a[i]=a[i-1]*i%mod;
    cin>>t;
    while(t--){
        memset(v,0,sizeof(v));
        int n,top=0;
        cin>>n;
        for(int i=1;i<=n;i++)cin>>num[i];
        for (int i=1;i<=n;i++){
            if(!v[i]){
                int pp=1;
                v[i]=1;
                for(int j=num[i];j!=i;j=num[j])++pp,v[j]=1;
                l[++top]=pp;
            }
        }
        long long ans=1;
        for(int i=1;i<=top;i++)ans=ans*(l[i]==1?1:pow(l[i],l[i]-2))%mod,ans=ans*pow(a[l[i]-1],mod-2)%mod;
        ans=ans*a[n-top]%mod;
        cout<<ans%mod<<"\n";
    }
	return 0;
}