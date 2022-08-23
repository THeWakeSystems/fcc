#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define lop(i,r,l) for(int i=r;i>=l;i--)
#define i8 __int128
#define __int128 ll
inline int read()//fast read
{
	int ret = 0, sgn = 1;
	char chr = getchar();
	while(chr < '0' || chr > '9')
	{if(chr == '-') sgn = -1; chr = getchar();}
	while(chr >= '0' && chr <= '9')
	{ret = ret * 10 + chr - '0'; chr = getchar();}
	return ret * sgn;
}
const int N=1e5+50;
const ll mod=1e9+7;
inline ll ksm(ll x,ll y)
{
	ll ret=1;
	while(y)
	{
		if(y&1) ret*=x,ret%=mod;
		x*=x,x%=mod;
		y>>=1;
	}
	return ret;
}
inline ll inv(ll x)
{
	return ksm(x,mod-2);
}
ll f[N],pw2[N],invf[N];
inline void init()
{
	f[0]=1,pw2[0]=1,invf[0]=1;
	rep(i,1,N-10)
	{
		f[i]=f[i-1]*i,f[i]%=mod;
		pw2[i]=pw2[i-1]*2,pw2[i]%=mod;
	}
	invf[N-10]=inv(f[N-10]);
	lop(i,N-11,1)
        invf[i]=invf[i+1]*(1ll*i+1)%mod;
}
inline ll cb(ll x,ll y)
{
	if(y<0||x<y) return 0;
	return f[x]*invf[y]%mod*invf[x-y]%mod;
}
struct query{
	int l,r,id;
}q[N];
int kl,kcnt,inbl[N];
ll ans[N],now,inv2;
inline bool cmp(query A,query B)
{
	if(inbl[A.l]^inbl[B.l]) return inbl[A.l]<inbl[B.l];
	if(inbl[A.l]&1) return A.r<B.r;
	return A.r>B.r;
}
int main()
{
	int m;
	m=read();
	init();
	int n=N-20;
	kl=sqrt(n);
	kcnt=ceil((db)n/kl);
	rep(i,1,kcnt)
		rep(j,(i-1)*kl+1,i*kl)
			inbl[j]=i;
	inv2=inv(2);
	rep(i,1,m)
	{
		q[i].id=i;
//		scanf("%d%d",&q[i].r,&q[i].l);
		q[i].r=read(),q[i].l=read();
	}
	sort(q+1,q+1+m,cmp);
	int l=1,r=0;
	rep(i,1,m)
	{
		int ql=q[i].l,qr=q[i].r;
		while(l<ql)
		{
			now+=cb(r,++l),now%=mod;
		}
		while(l>ql)
		{
			now-=cb(r,l--),now=(now+mod)%mod;
		}
		while(r<qr)
		{
			now=2*now-cb(r++,l),now=(now+mod)%mod;
		}
		while(r>qr)
		{
			now=(now+cb(--r,l))%mod*inv2,now%=mod;
		}
		ans[q[i].id]=(now*inv(pw2[q[i].r])+1)%mod;
	}
	rep(i,1,m) printf("%lld\n",ans[i]);
	return 0;
}