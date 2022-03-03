#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
typedef long long ll; 
const int N=5e5+5;
const ll mod=1e9+7;
ll a[N];
void solve(){
	int n;scanf("%d",&n);
	ll g=0,ans=0;
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
		g=__gcd(g,a[i]);
		ans=(ans+a[i])%mod;
	}
	for(int i=1;i<=n;++i){
		ll x=a[i];
		for(int j=i+1;j<=n;++j){
			x=__gcd(a[j],x);
			if(x==g){
				ans=(ans+1LL*(n-j+1)*x%mod)%mod;
				break;
			}
			ans=(ans+x)%mod;
		}
	}
	printf("%lld\n",ans);
}
int main(){
	solve();
	return 0;
}