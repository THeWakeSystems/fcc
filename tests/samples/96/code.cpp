#include<bits/stdc++.h>

using namespace std;

int a[1005], sg[1005];

vector<int> g[1005];

int ma[1005];

void init()
{
    sg[1]=0;
    for(int i=2;i<=1000;i++)
    {
        for(int j=1;j<i;j++)
        {
            if(i%j==0)
            {
                g[i].push_back(j);
            }
        }
    }
    for(int i=2;i<=1000;i++)
    {
        memset(ma,0,sizeof(ma));
        for(int j=0;j<g[i].size();j++)
        {
            int ans=0;
            for(int k=0;k<g[i].size();k++)
            {
                if(k==j)
                {
                    continue;
                }
                ans^=sg[g[i][k]];
            }
            ma[ans]++;
        }
        int ji=0;
        while(ma[ji])
        {
            ji++;
        }
        sg[i]=ji;
    }
}

int main()
{
    int n;
    init();
    while(~scanf("%d",&n))
    {
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
        }
        int ans=0;
        for(int i=1; i<=n; i++)
        {
            ans^=sg[a[i]];
        }
        if(ans)
        {
            printf("freda\n");
        }
        else
        {
            printf("rainbow\n");
        }
    }
}
