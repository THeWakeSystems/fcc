#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
#define ll long long
#define re register
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define P pair<int,int>
void read(int &a)
{
    a=0;
    int d=1;
    char ch;
    while(ch=getchar(),!isdigit(ch))
        if(ch=='-')
            d=-1;
    a=ch^48;
    while(ch=getchar(),isdigit(ch))
        a=(a<<3)+(a<<1)+(ch^48);
    a*=d;
}
void write(int x)
{
    if(x<0)
        putchar(45),x=-x;
    if(x>9)
        write(x/10);
    putchar(x%10+'0');
}
double dp[305][305],a[305];
int main()
{
    int T;
    read(T);
    while(T--)
    {
        memset(dp,0,sizeof(dp));
        memset(a,0,sizeof(a));
        int n;
        read(n);
        for(re int i=0;i<n;i++)
            scanf("%lf",&a[i]);
        for(re int i=n-1;i>=0;i--)
            for(re int j=n-1;j>=0;j--)
            {
                dp[i][j]=(a[i]*dp[i+1][j]+1+(1-a[i])*(a[j]*dp[j+1][i]+1))/(1-(1-a[i])*(1-a[j]));
                dp[j][i]=(a[j]*dp[j+1][i]+1+(1-a[j])*(a[i]*dp[i+1][j]+1))/(1-(1-a[i])*(1-a[j]));
            }
        printf("%.4lf\n",dp[0][0]);
    }
    return 0;
}