#include<bits/stdc++.h>
using namespace std;
int t1=1,t2=1;
int f[1000005],a[1000005];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	f[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		if(a[i]>=f[t1])
		{
			f[++t1]=a[i];
		}
		else
		{
			int idx=upper_bound(f+1,f+1+t1,a[i])-f;
			f[idx]=a[i];
		}
	}
	
	memset(f,0,sizeof(f));
	f[1]=a[n];
	for(int i=n-1;i>=1;i--)
	{
		if(a[i]>=f[t2])
			f[++t2]=a[i];
		else
		{
			int idx=upper_bound(f+1,f+1+t2,a[i])-f;
			f[idx]=a[i];
		}
	}
	int mx=0;
	mx=max(t1,t2);
	cout<<n-mx;
	return 0;
 } 