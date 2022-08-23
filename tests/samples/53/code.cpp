#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
#include<stdlib.h>
#define ll long long
#define inf 9999999
using namespace std;
struct node{
	int x,y;
}a[100010];
int b[100010];
bool cmp(int a,int b)
{
	return a<b;
}
int main()
{
	int n,t;
	while(cin>>n>>t)
	{
		memset(a,0,sizeof(a));
		memset(b,inf,sizeof(b));
		for(int i=1;i<=n;i++)
		cin>>a[i].x>>a[i].y;
		for(int i=2;i<=n;i++) b[i]=a[i].x+1-a[i-1].y;
		sort(b+1,b+n+1,cmp);
		int s=0;
		for(int i=1;i<=n;i++)
		{
			t-=b[i]; 
			if(t>=0)
			{
				s++;
				//printf("%d %d %d %d\n",i,s,t,b[i]);
			}
			else  break;
		}
		printf("%d\n",s);
	}
	return 0;	
}