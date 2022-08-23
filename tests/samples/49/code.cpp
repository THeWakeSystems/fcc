#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long sa=0,sb=0,n,anss[35],s,i,x;
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>x;
			sa+=x;
		}
		for(i=0;i<n;i++)
		{
			cin>>x;
			sb+=x;
		}
		s=sa*sb;
		anss[0]=s/n;
		for(i=1;i<=31;i++)
		{
			s=s%n*10;
			anss[i]=s/n;
		}
		if(anss[31]>=5)
		anss[30]++;
		i=30;
		while(i>0)
		{
			if(anss[i]==10)
			{
				anss[i]=0;
				i--;
				anss[i]++;
				
				
			}
			else 
			break;
		}
		printf("%lld.",anss[0]);
		for(i=1;i<=30;i++)
		printf("%d",anss[i]);
		printf("\n");
	}
	return 0;
}