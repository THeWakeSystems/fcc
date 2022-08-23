#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
int n,b[(int)(1e6+10)],base=26;
char s1[(int)(1e6+10)],s2[(int)(1e6+10)];
int f1[(int)(1e6+10)],f2[(int)(1e6+10)];
int g1[(int)(1e6+10)],g2[(int)(1e6+10)];
int qian(int l,int r,int id)
{
	if(id==1) return (f1[r]-f1[l-1]%mod*b[r-l+1]%mod+mod)%mod;
	else return (g1[r]-g1[l-1]%mod*b[r-l+1]%mod+mod)%mod;
}
int hou(int l,int r,int id)
{
	if(id==1) 
	{
		return (f2[r]-f2[l-1]%mod*b[r-l+1]%mod+mod)%mod;
	}
	else return (g2[r]-g2[l-1]%mod*b[r-l+1]%mod+mod)%mod;
}
char s3[(int)(1e6+10)];
int get()
{
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int l=0,r=min(i-1,n-i),find=0;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(qian(i-mid,i-1,1)==hou(n-(i+mid)+1,n-(i+1)+1,1)) find=mid,l=mid+1;
			else r=mid-1;
		}
		ans=max(ans,2*find+1);
		int st=i-find,ed=i+find;
		l=0,r=min(st-1,n-ed),find=0;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			// cout<<st-mid<<" "<<st-1<<" "<<n-ed-mid+2<<" "<<n-ed+1<<" "<<(qian(st-mid,st-1,1)==hou(n-ed-mid+2,n-ed+1,2))<<"\n";
			if(qian(st-mid,st-1,1)==hou(n-ed-mid+2,n-ed+1,2)) find=mid,l=mid+1;
			else r=mid-1;
		}
		ans=max(ans,find*2+ed-st+1);
		// cout<<ed<<" "<<st<<" "<<find<<" "<<ans<<"\n";
	}
	for(int i=1;i<=n;i++)
	{
		int l=0,r=min(i-1,n-i),find=0;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(qian(i-mid+1,i,1)==hou(n-(i+mid)+1,n-(i+1)+1,1)) find=mid,l=mid+1;
			else r=mid-1;
		}
		ans=max(ans,2*find);
		int st=i-find+1,ed=i+find;
		l=0,r=min(st-1,n-ed),find=0;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(qian(st-mid,st-1,1)==hou(n-ed-mid+2,n-ed+1,2)) find=mid,l=mid+1;
			else r=mid-1;
		}
		ans=max(ans,find*2+ed-st+1);
	}
	return ans;
}
void get_hash()
{
	for(int i=1;i<=n;i++)
	{
		f1[i]=(f1[i-1]*base+s1[i])%mod;
		g1[i]=(g1[i-1]*base+s2[i])%mod;
	}
	for(int i=1;i<=n;i++)
	{
		s3[i]=s1[n-i+1];
	}
	for(int i=1;i<=n;i++)
	{
		f2[i]=(f2[i-1]*base+s3[i])%mod;
	}
	for(int i=1;i<=n;i++)
	{
		s3[i]=s2[n-i+1];
	}
	for(int i=1;i<=n;i++)
	{
		g2[i]=(g2[i-1]*base+s3[i])%mod;
	}
}
signed main()
{
	cin>>n;
	cin>>(s1+1)>>(s2+1);
	b[0]=1;
	for(int i=1;i<=n;i++)
	{
		b[i]=(b[i-1]*base)%mod;
	}
	get_hash();
	int ans=0;
	ans=max(ans,get());
	for(int i=1;i<=n;i++)
	{
		s3[i]=s2[n-i+1];
	}
	for(int i=1;i<=n;i++)
	{
		s2[i]=s3[i];
	}
	for(int i=1;i<=n;i++)
	{
		s3[i]=s1[n-i+1];
	}
	for(int i=1;i<=n;i++)
	{
		s1[i]=s3[i];
	}
	for(int i=1;i<=n;i++)
	{
		swap(s1[i],s2[i]);
	}
	get_hash();
	cout<<max(ans,get());
}
