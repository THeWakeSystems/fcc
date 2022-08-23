#include<iostream>

using namespace std;
int main()
{
	int t=0,a[23];
	cin>>t;
	for(int i=0;i<t;i++){
		int sum=0,minn=1001;
		for (int j=0;j<23;j++){
					cin>>a[j];
		sum+=a[j];		
			minn=min(minn,a[j]);		
		}
		cout<<sum*minn<<endl;
	}	
}