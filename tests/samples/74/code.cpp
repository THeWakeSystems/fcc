#include <bits/stdc++.h>
using namespace std;
const int N=50000,mod=999911658;
typedef long long ll;
ll n,G,fac[N],a[5],b[5]={0,2,3,4679,35617},val;
ll power(ll a,ll b,ll p){
	ll res=1;
	for(;b;b>>=1){
		if(b&1) res=res*a%p;
		a=a*a%p;
	}
	return res;
}
void init(ll p){
	fac[0]=1;
	for(ll i=1;i<=p;i++) fac[i]=fac[i-1]*i%p;
}
ll C(ll n,ll m,ll p){
	if(n<m) return 0;
	return fac[n]*power(fac[m],p-2,p)%p*power(fac[n-m],p-2,p)%p;
}
ll lucas(ll n,ll m,ll p){
	if(n<m) return 0;
	if(n==0) return 1;
	return lucas(n/p,m/p,p)*C(n%p,m%p,p)%p;
}
void CRT(){
	for(ll i=1;i<=4;i++){
		val=(val+a[i]*(mod/b[i])%mod*power(mod/b[i],b[i]-2,b[i]))%mod;
	}
}
int main(){

	cin>>n>>G;
	if(G%(mod+1)==0) {
		cout<<"0"<<endl;
		return 0;
	}	
	for(ll k=1;k<=4;k++){
		init(b[k]);
		for(ll i=1;i<=n/i;i++){
			if(n%i==0){
				a[k]=(a[k]+lucas(n,i,b[k]))%b[k];
				if(i*i!=n) a[k]=(a[k]+lucas(n,n/i,b[k]))%b[k];
			}
		}
	}
	CRT();
	cout<<power(G,val,mod+1)<<endl;
	
	getchar();
	system("pause");
	return 0;
}