#include<bits/stdc++.h>
using namespace std;
int a[2001];
int n,ans[2001];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];
		}
		sort(a+1,a+n+1);
		ans[i]=a[(n/2)+1];
		
	}
	sort(ans+1,ans+n+1);
	cout<<ans[(n/2)+1];
}