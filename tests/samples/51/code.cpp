#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	int n;
	while(T--)
	{
		cin>>n;
		cout<<int(log(n)/log(2))+1<<endl;
	}
    return 0;
}