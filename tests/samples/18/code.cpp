#include<bits/stdc++.h>
using namespace std;

long long a[2000010],sum[2000010],n,s;

int main(){
    cin>>n>>s;
    for(int i=1;i<=n;i++) {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1,greater<long long>());
    for(int i=1;i<=2*n;i++) sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;i++){
        long long dam=0;
        for(int k=1;k<=n;k+=i){
            dam+=max((long long)0,sum[i+k-1]-sum[k-1]-s);
        }
        printf("%lld\n",dam);
    }
    return 0;
}