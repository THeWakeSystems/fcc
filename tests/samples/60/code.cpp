#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<vector>
using namespace std;
long long n,m,w,head[100001],duilie[10000001],to[100001],pd=0,arrive[100001];
struct sr
{
	long long from,to,cost,next;
}a[400001];
bool b[100001];
void add(long long i,long long f,long long t,long long c)
{
	a[i].from=f;
	a[i].to=t;
	a[i].cost=c;
	a[i].next=head[f];
	head[f]=i;
}
int main()
{
	memset(head,0,sizeof(head));
	memset(to,0x7f,sizeof(to));
	memset(arrive,0,sizeof(arrive));
	long long i,j,k,f,t,c;
	scanf("%lld%lld%lld",&n,&m,&w);
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&f,&t,&c);
		add(i,f,t,c);
		add(m+i,t,f,c);
	}
	for(i=1;i<=w;i++)
	{
		scanf("%lld%lld%lld",&f,&t,&c);
		c=0-c;
		add(m*2+i,f,t,c);
	}
	i=1;
	j=1;
	duilie[1]=1;
	to[1]=0;
	for(i=1;i<=j;i++)
	{
		if(pd==1)
		{
			break;
		}
		b[duilie[i]]=0;
		for(k=head[duilie[i]];k!=0;k=a[k].next)
		{
			if(to[a[k].from]+a[k].cost<to[a[k].to])
			{
				to[a[k].to]=to[a[k].from]+a[k].cost;
				arrive[a[k].to]++;
				if(arrive[a[k].to]>n)
				{
					pd=1;
					break;
				}
				if(b[a[k].to]==0)
				{
					j++;
					duilie[j]=a[k].to;
					b[a[k].to]=1;
				}
			}
		}
	}
	if(pd==1)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}