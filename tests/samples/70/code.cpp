#include <bits/stdc++.h>
using namespace std;
const int mod=10007;
int ch[1009][1009]= {0};
int main()
{
    int a,b,k,n,m,x=0,y=1;
    int i,j;
    cin>>a>>b>>k>>n>>m;
    for(i=0; i<n; i++)
        y=(y*(a%mod))%mod;
    for(i=0; i<m; i++)
        y=(y*(b%mod))%mod;
    ch[1][1]=1;
    for(i=0; i<1006; i++)
    {
        for(j=0; j<=i; j++)
        {
            if(j==0)
                ch[i][j]=1;
            else
                ch[i][j]=(ch[i-1][j]+ch[i-1][j-1])%mod;
        }
    }
    /*for(i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
            cout<<ch[i][j]<<' ';
        cout<<endl;
    }*/
    x=((ch[k][n]%mod)*(y%mod))%mod;
    cout<<x;
    return 0;
}
