#include <iostream>
#include<cstring>
#include<cmath>
using namespace std;
const int N=100000;
const int mod=1e9+7;
int coin[]={1,2,5,10,20,50,100,200,500,1000,2000,5000,10000};
int main()
{
    int t,n;
    int dp[N];
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=0;i<13;i++){
            for(int j=coin[i];j<=n;j++){
                dp[j]=(dp[j]+dp[j-coin[i]])%mod;
            }
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}
