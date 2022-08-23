#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
int a[30010],f[30010];
int main()
{
	int n,ans=2e9;
	cin>>n;
	for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    	f[i]=f[i-1]+a[i]-1;
	}
	for(int i=0;i<=n;i++)
	{
		int a=i-f[i],b=f[n]-f[i];
		ans=min(ans,abs(a-i)+abs(b-n+i));
	}
	cout<<ans<<"\n";
	return 0;
}