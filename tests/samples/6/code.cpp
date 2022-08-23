#include<bits/stdc++.h>
#define nn 2000010
#define mm 4000010
#define inf -100000000
using namespace std;
map<pair<int,int>,int> fi;
pair<int,int> in;
int xi[8]={-1,-1,-1,0,0,1,1,1},yi[8]={-1,0,1,-1,1,-1,0,1};
int x[nn],y[nn];
int fir[nn<<1],nxt[mm<<1],to[mm<<1],ti[nn],li[nn],rep[nn],sta[nn],mo[nn<<1],dis[nn<<1],q[nn<<1],du[nn<<1];
bool vis[nn<<1];
int e=0,l=0,t=0,ne,h;
int read()
{
    int ans=0,f=1;char ch=getchar();
    while(!isdigit(ch)) {if(ch=='-') f=-1;ch=getchar();}
    while(isdigit(ch)) {ans=ans*10+ch-'0';ch=getchar();}
    return ans*f;
}
void add(int u,int v)
{
    nxt[++e]=fir[u];fir[u]=e;to[e]=v;
}
int cmp1(int a,int b)
{
    if(x[a]==x[b])
      return ti[a]<ti[b];
    return x[a]<x[b];
}
int cmp2(int a,int b)
{
    if(y[a]==y[b])
      return ti[a]<ti[b];
    return y[a]<y[b];
}
void tarjan(int now)
{
    int sum=1;
    vis[now]=1;
    ti[now]=li[now]=++l;sta[++t]=now;
    for(int i=fir[now];i;i=nxt[i])
      if(!ti[to[i]])                  ////
      {
          tarjan(to[i]);
          li[now]=min(li[now],li[to[i]]);
      }
      else if(vis[to[i]]&&li[now]>ti[to[i]])                 ////
          li[now]=ti[to[i]];               ////
    if(li[now]==ti[now])
    {
        ne++;
        while(sta[t]!=now)
        {
            vis[sta[t]]=0;
            rep[sta[t]]=ne;
            sum++;
            t--;
        }
        mo[ne]=sum;
        rep[sta[t]]=ne;
        vis[sta[t]]=0;t--;
    }
}
int dp(int n)
{
    int o,an=-1;
    while(h<=t)
    {
        o=q[h++];
        if(dis[o]>an)
          an=dis[o];
        for(int i=fir[o];i;i=nxt[i])
        {
            du[to[i]]--;
            if(dis[to[i]]<dis[o]+mo[to[i]])
              dis[to[i]]=dis[o]+mo[to[i]];
            if(!du[to[i]])
              q[++t]=to[i];
        }
    }
    return an;
}
int main()
{
//    freopen("o.txt","r",stdin);
//    freopen("o.out","w",stdout);
    int n=read(),r=read(),c=read();
    ne=n;
    for(int i=1;i<=n;i++)
    {
        in.first=read();in.second=read();
        x[i]=in.first;y[i]=in.second;
        ti[i]=read();
        fi[in]=i;
        li[i]=i;
    }
    for(int i=1;i<=n;i++)
      if(ti[i]==3)
        for(int j=0;j<8;j++)
        {
            in.first=x[i]+xi[j];
            in.second=y[i]+yi[j];
            if(fi.find(in)!=fi.end())
              add(i,fi[in]);
        }
    sort(li+1,li+n+1,cmp1);
    for(int i=1;i<=n;i++)
      {
          int fi=0,la=0,j;
          for(j=i;j<=n&&x[li[i]]==x[li[j]];j++)
          if(ti[li[j]]==1)
          {
                if(!fi) fi=j;
                la=j;
                if(fi!=la)
                  add(li[j-1],li[j]);
        }
          if(fi)
          {
              if(fi!=la)
                add(li[la],li[fi]);
              for(j=i;j<=n&&x[li[i]]==x[li[j]];j++)
                if(ti[li[j]]!=1)
                  add(li[la],li[j]);
          }
          i=j-1;
      }
    for(int i=1;i<=n;i++)
      li[i]=i;
    sort(li+1,li+n+1,cmp2);
    for(int i=1;i<=n;i++)
      {
          int fi=0,la=0,j;
          for(j=i;j<=n&&y[li[i]]==y[li[j]];j++)
          if(ti[li[j]]==2)
          {
                if(!fi) fi=j;
                la=j;
                if(fi!=la)
                  add(li[j-1],li[j]);
        }
          if(fi)
          {
              if(fi!=la)
              add(li[la],li[fi]);
              for(j=i;j<=n&&y[li[i]]==y[li[j]];j++)
                if(ti[li[j]]!=2)
                  add(li[la],li[j]);
          }
          i=j-1;
      }
    fill(ti,ti+n+1,0);
    fill(li,li+n+1,0);
    for(int i=1;i<=n;i++)
      if(!ti[i])
        tarjan(i);
    for(int i=1;i<=n;i++)
      for(int j=fir[i];j;j=nxt[j])
        if(rep[i]!=rep[to[j]])
        {
            add(rep[i],rep[to[j]]);
            du[rep[to[j]]]++;
        }
    h=1,t=0;
    for(int i=n+1;i<=ne;i++)
      if(!du[i])
      {
          q[++t]=i;
          dis[i]=mo[i];
      }
    printf("%d",dp(n));
    return 0;
} 