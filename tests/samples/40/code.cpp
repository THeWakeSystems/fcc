#include<bits/stdc++.h>
#define debug(x) cout<<"[debug]"#x<<"="<<x<<endl;
#define int long long
#define endl "\n"
using namespace std;
typedef pair<int,int> PII; 
typedef vector<int> vi;
int n,m,t;
const int N=5e4+10;
int a[N];
int sum[N];
signed main()
{
	ios::sync_with_stdio(false);
	//freopen("1.txt", "r", stdin)
	cin>>t;
	 while(t--)
	 {
	 	cin>>n;
	 	memset(a,0,sizeof(a));
	 	memset(sum,0,sizeof(sum));
	 	int ans=0;
	 	for(int i=1;i<=n;i++)
	 	{
	 		cin>>a[i];
	 		ans+=a[i]*a[i];
	 		sum[i]=sum[i-1]+a[i];
		}
		ans=ans*(n-1);
		for(int i=1;i<=n;i++)
		{
			ans+=(-2)*(a[i])*(sum[i-1]);
		} 
		cout<<ans<<endl;
	 }
	return 0;
} 