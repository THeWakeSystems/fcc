#include <iostream>
#include <cstring>
using namespace std;

int dp[2][20];

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int ans=0;
        memset(dp,0,sizeof dp);
        for(int i=0;i<n;i++)
        {
            int c,a;
            cin>>c>>a;
            for(int j=1;j<=10;j++)
            {
                if(j!=a)
                    dp[c][a]=max(dp[c][a],dp[1-c][j]+1);
                ans=max(ans,dp[c][a]);
            }
        }
        cout<<ans<<endl;
    }
}