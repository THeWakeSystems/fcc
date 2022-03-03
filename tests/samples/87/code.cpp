#include <bits/stdc++.h>
using namespace std;
const int N=100010, M=32*N;
int n, ans, idx;
int son[M][2];

void insert(int x)
{
    int p=0;
    for (int i=31;i>=0;i--)
    {
        int u=x>>i&1;
        if (!son[p][u]) son[p][u]=++idx;
        p=son[p][u];
    }
}

int query(int x)
{
    int p=0, res=0;
    for (int i=31;i>=0;i--)
    {
        int u=x>>i&1;
        if (son[p][!u])
        {
            res=(res<<1)+!u;
            p=son[p][!u];
        }
        else
        {
            res=(res<<1)+u;
            p=son[p][u];
        }
    }
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i=1;i<=n;i++)
    {
        int x;
        scanf("%d", &x);
        int t=query(x);
        insert(x);
        ans=max(ans, x^t);
    }
    printf("%d\n", ans);
    return 0;
}