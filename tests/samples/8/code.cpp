#include<iostream>
#include<cstring>
using namespace std;
char c[200000],b[200000];
int main()
{
	int a;
	cin>>a;
	while(a--)
	{
		cin>>b>>c;
		if(strlen(b)!=strlen(c))
		{
			cout<<"TAT"<<endl;
			continue;
		}
		else 
		{
			int i,d;
			for( i=0,d=strlen(b)-1;d>=0;i++,d--)
			{
				if(b[i]!=c[d])break;
			}
			if(d>=0)cout<<"TAT"<<endl;
			else cout<<"QAQ"<<endl;
		}
	}
	return 0;
}