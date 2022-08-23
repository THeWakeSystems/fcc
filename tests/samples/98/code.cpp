#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int MAXN = 1205;
int fa[MAXN],sz[MAXN];
int tot;
int n,p1,p2;
int N;
void ini()
{
    tot = 0;
    N = p1 + p2;
    for(int i = 0;i <= N;++i)
    {
        fa[i] = i;
        fa[i + N] = i + N;
        sz[i] = 1;
        sz[i + N] = 0;
    }
}
int Find(int x)
{
    if(x == fa[x])  return x;
    return fa[x] = Find(fa[x]);
}
void merge(int x,int y)
{
    x = Find(x);
    y = Find(y);
    if(x != y)  {
        fa[x] = y;
        sz[y] += sz[x];
    }
}
int a[MAXN];
int b[MAXN];
int f1[MAXN];
int dp[MAXN][MAXN];
int main()
{
    while(~scanf("%d %d %d",&n,&p1,&p2))
    {
        if(n == 0 && p1 == 0 && p2 == 0)    break;
        ini();
        for(int i = 0;i < n;++i)
        {
            int x,y;
            char s[10];
            scanf("%d %d %s",&x,&y,s);
            if(s[0] == 'y')
            merge(x,y),merge(x + N,y + N);
            else
            merge(x,y + N),merge(x + N,y);
        }
        memset(f1,0,sizeof f1);
        for(int i = 1;i <= N;i++)
        {
            int fa = Find(i);
            if(fa == i)
            {
                f1[fa] = f1[Find(i + N)] = ++tot;
                a[tot] = sz[fa];
                b[tot] = sz[Find(i + N)];
            }
        }
        memset(dp,0,sizeof dp);
        dp[0][0] = 1;
        for(int i = 1;i <= tot;++i)
        for(int j = p1;j >= min(a[i],b[i]);--j)
        {
            if(j >= a[i])
            dp[i][j] += dp[i - 1][j - a[i]];
            if(j >= b[i])
            dp[i][j] += dp[i - 1][j - b[i]];
        }
        if(dp[tot][p1] != 1)
        puts("no");
        else
        {
            int now = p1;
            for(int i = tot;i >= 1;--i)
            {
                if(dp[i - 1][now - a[i]])
                now -= a[i],a[i] = 1;
                else
                now -= b[i],a[i] = 2;
            }
            for(int i = 1;i <= N;++i)
            {
                    int r = a[f1[Find(i)]];
                    if(r == 1 && Find(i) <= N)   printf("%d\n",i);
                    else if(r == 2 && Find(i) > N)   printf("%d\n",i);
            }
            puts("end");
        }
    }
    return 0;
}