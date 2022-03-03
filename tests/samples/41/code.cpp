#include<bits/stdc++.h>
#define debug(x) cout<<"[debug]"#x<<"="<<x<<endl;
#define int long long
#define endl "\n"
using namespace std;
typedef pair<int,int> PII; 
typedef vector<int> vi;
int n,m,t;
const int N=1e6+10;
string str;
signed main()
{
	ios::sync_with_stdio(false);
	//freopen("1.txt", "r", stdin);
	cin>>str;
	int ans=0;
	for(int i=0;i<str.size();i++)
	{
		int res=0;
		for(int j=i,k=i+1;j>=0&&k<str.size();j--,k++)
		{
			if(abs(str[j]-str[k])==32)
			{
				res+=2;
			}
			else
			{
				break;
			}
		}
		ans=max(res,ans);
	}
	cout<<ans;
	return 0;
} 