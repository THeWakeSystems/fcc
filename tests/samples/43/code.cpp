#include<bits/stdc++.h>
#define debug(x) cout<<"[debug]"#x<<"="<<x<<endl;
#define int long long
#define endl "\n"
using namespace std;
typedef pair<int,int> PII; 
typedef vector<int> vi;
int n,m,t;
const int N=1e6+10;
int Count(long long Num) 
{
  long long res = 0;
  while (Num) {
    res += Num % 10;
    Num /= 10;
  }
  return res;
}
signed main()
{
	ios::sync_with_stdio(false);
	//freopen("1.txt", "r", stdin);
	int T;
	 long long N;
   cin>>T;
  	while(T--) 
	{
		cin>>n;
	    long long d = 0;
	    while (d * 10 + 9 <= n) d = d * 10 + 9;
	    cout<<Count(d) + Count(n - d)<<endl;
  	}
	return 0;
} 