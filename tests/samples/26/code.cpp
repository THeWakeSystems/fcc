#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <sys/time.h> 
#define M 100005
#define ld long double
using namespace std;
int fa[M],c[M],v[M],tot=0,n,m,du[M],now=0,h[M],root;
ld g[M],f[M],d[M],gg[M];
struct edge
{
    int y,ne,l;
}e[M*5];
void Addedge(int x,int y,int l)
{
    tot++;
    e[tot].y=y;
    e[tot].ne=h[x];
    e[tot].l=l;
    h[x]=tot;
}
void Dfs(int x)
{
    d[x]=f[x]=0.000;
    v[x]=1;
    du[x]=0;
    for (int i=h[x];i;i=e[i].ne)
    {
        int y=e[i].y;
        if (v[y]||c[y]) continue;
        Dfs(y);
        du[x]++;
        d[x]=d[x]+f[y]+(ld)e[i].l;
    }
    if (du[x]) f[x]=d[x]/(ld)du[x];
    if (x!=root) du[x]++;
}
void Dfs2(int x)
{
    v[x]=1;
    for (int i=h[x];i;i=e[i].ne)
    {
        int y=e[i].y;
        if (v[y]||c[y]) continue;
        int k=du[x]-1;
        if (!k) k++;
        d[y]=d[y]+(d[x]-f[y]-(ld)e[i].l)/(ld)(k)+(ld)e[i].l;
        Dfs2(y);
    }
}
void Findcir(int x)
{
    v[x]=++now;
    for (int i=h[x];i;i=e[i].ne)
    {
        int y=e[i].y;
        if (!v[y])
        {
            fa[y]=x;
            Findcir(y);
        }
        else if (y!=fa[x]&&v[y]<v[x])
        {
            c[y]=1;
            while (x!=y)
            {
                c[x]=1;
                x=fa[x];
            }
            return;
        }
    }
}
void Calc(int x,int fa)
{
    bool last=true;
    g[x]=0.000;
    for (int i=h[x];i;i=e[i].ne)
    {
        int y=e[i].y;
        if (y!=root&&y!=fa&&c[y])
        {
            last=false;
            Calc(y,x);
            g[x]=g[x]+g[y]+(ld)e[i].l;
        }
    }
    int k=du[x];
    if (!k) k++;
    if (last) g[x]=d[x]/(ld)k;
    else
    {
        k=du[x]+1;
        if (x!=root)
            g[x]=(g[x]+d[x])/(ld)k;
        else
        {
            return;
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
    {
        int x,y,l;
        scanf("%d%d%d",&x,&y,&l);
        Addedge(x,y,l);
        Addedge(y,x,l);
    }
    struct timeval start;
    struct timeval end;
    float time_use=0;
    gettimeofday( &start, NULL );
    if (n==m+1)
    {
        root=1;
        Dfs(1);
        for (int i=1;i<=n;i++)
            v[i]=0;
        Dfs2(1);
    }
    else
    {
        Findcir(1);
        for (int i=1;i<=n;i++)
            v[i]=0;
        for (int i=1;i<=n;i++)
            if (c[i]) root=i,Dfs(i);
        for (int i=1;i<=n;i++)
            if (c[i]) root=i,Calc(i,0),gg[i]=g[i];
        for (int i=1;i<=n;i++)
            if (c[i]) du[i]+=2,d[i]+=gg[i];
        for (int i=1;i<=n;i++)
            v[i]=0;
        for (int i=1;i<=n;i++)
            if (c[i]) Dfs2(i);
    }
    double ans=0.000;
    for (int i=1;i<=n;i++)
        ans=ans+d[i]/(ld)du[i];
    gettimeofday( &end, NULL );
    time_use=(end.tv_sec-start.tv_sec)*1000000+(end.tv_usec-start.tv_usec);//微秒
    
    printf("%.5lf\n",ans/(double)n);
    printf("time_use is %f\n",time_use);
    return 0;
}
