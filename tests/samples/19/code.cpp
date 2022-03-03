#include<bits/stdc++.h>
using namespace std;
const int N=3e6+100;
int a[N],b[N];

inline int read()
{
	int x=0,p=1;
	char c=getchar();
	while(c>'9'||c<'0')
	{
		if(c=='-') p=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*p;
}

int main()
{
	int ans=0,n;
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read(),b[i]=read();
		int x=max(a[i-1],b[i-1]),y=min(a[i],b[i]);
		if(x<=y)
		{
			ans+=y-x+1;
			if(a[i-1]==b[i-1]) ans--;
		}
	}
	printf("%d\n",ans);
	return 0;
}