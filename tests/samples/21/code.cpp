#include<bits/stdc++.h>
#define mod 998244353
#define maxn 1000000
using namespace std;
int n,A[200005],f[1000005],g[1000005],F[1000005],G[1000005],inv2=(mod+1)/2; 
int inv[1000005],ans;

int read(){
	int x=0,w=0;char ch=getchar();
	while(!isdigit(ch)) w|=(ch=='-'),ch=getchar();
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return w?-x:x;
}

void print(int x){
	if(x>=10) print(x/10);
	putchar(x%10+'0'); 
}

int main(){
	n=read();
	for(int i=1;i<=n;i++){
		A[i]=read();
		(f[A[i]]+=A[i])%=mod;
		(g[A[i]]+=1ll*A[i]*A[i]%mod)%=mod;
	}
	for(int i=1;i<=maxn;i++){
		for(int j=i;j<=maxn;j+=i){
			(F[i]+=f[j])%=mod;
			(G[i]+=g[j])%=mod;
		}
		F[i]=1ll*F[i]*F[i]%mod;
		(F[i]+=mod-G[i])%=mod;
		F[i]=1ll*F[i]*inv2%mod;
	}
	for(int i=maxn;i>=1;i--){
		for(int j=i+i;j<=maxn;j+=i) (F[i]+=mod-F[j])%=mod;
	}
	inv[1]=1;
	for(int i=2;i<=maxn;i++) inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	for(int i=1;i<=maxn;i++) (ans+=1ll*F[i]*inv[i]%mod)%=mod;
	print(ans),puts("");
	
	return 0;
}