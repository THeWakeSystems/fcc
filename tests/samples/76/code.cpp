#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N,X;
	while(cin>>N>>X)
	{
		int a[1000]= {0},b[1000]= {0};
		bool ans=false;
		for(int i=0; i<N; i++)
			cin>>a[i];
		for(int i=0; i<N; i++)
			cin>>b[i];
		if(a[0]==1&&a[X-1]==1)ans=true;
		else if(a[0]==1)
		{
			if(b[X-1]==1)
			{
				for(int i=X; i<N; i++)
					if(a[i]==1&&b[i]==1){ans=true;break;}
			}
		}
		if(ans==true)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}