#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int n,m;
int X[1002];
double x[1002];
double ans=1e6;

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d",&X[i]);
	for(int i=1;i<=m;i++)
	{
		scanf("%lf",&x[i]);
		if(n<X[i])
		{
			if(n>=X[i-1])
				ans=min(ans,n*x[i]);
			else
				ans=min(ans,X[i-1]*x[i]);
		}	
	}
	printf("%lf",ans);	
} 