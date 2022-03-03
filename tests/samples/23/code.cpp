#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
const int N=100010;

int w[200][200],v[200][200],f[1000];
int n,x,m;
int s;

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		memset(f,0,sizeof f);
		s=0;
		cin>>n>>x>>m;
		int a[120];
		int nn=n;
		while(nn--)
			cin>>a[nn];
		sort(a,a+n,greater<int>());
        x=min(x,n);
		while(x--)
			s+=a[x];
		for(int i=1;i<=m;i++)
			for(int j=1;j<=s;j++)
			{
				cin>>w[i][j];
				v[i][j]=j;
			}
		for(int i=1;i<=m;i++)
		{
			for(int j=s;j>=0;j--)
			{
				for(int k=1;k<=s;k++)
				{
					if(j>=v[i][k])
					f[j]=max(f[j],f[j-v[i][k]]+w[i][k]);
				}
			}
		}
		cout<<f[s]<<endl;
	}
}