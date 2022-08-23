#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int sg[1000009],i,n,t; 
int dfs(int x)
{
	if(x==0)return 1;
    if(sg[x]!=-1)return sg[x];
	int k=x,flag=0,ma=1,mi=10;
	while(k>0)
	{
        ma=max(ma,k%10);
        if(k%10>0)mi=min(mi,k%10);
		k/=10;
	}
	flag+=dfs(x-ma)+dfs(x-mi);
    sg[x]=(flag==0?1:0);
	return sg[x];
}
int main()
{
	
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin>>t;
	memset(sg,-1,sizeof sg);
    sg[0]=0;
	while(t--)
	{
		cin>>n;
		
		if(dfs(n)==0)cout<<"YES"<<endl;
		else
		cout<<"NO"<<endl;
	}
	return 0;
 }