#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
int f[510];
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		f[i]=f[i-1]+a;
	}
	for(int i=1;i<=m;i++)
	{
		int a,b;
		cin>>a>>b;
		cout<<f[b]-f[a-1]<<"\n";
	}
	return 0;
}