#include <iostream>
#include <cstring>
#include <algorithm>
#include <deque>
using namespace std;
const int N=510;
typedef pair<int,int> PII;
#define x first
#define y second
int n,m;
char g[N][N];
bool st[N][N];
int dist[N][N];
int dx[4]={-1,-1,1,1},dy[4]={-1,1,-1,1};
int ix[4]={-1,-1,0,0},iy[4]={-1,0,-1,0};
char op[]="\\//\\";
int bfs()
{
    memset(st,0,sizeof st);
    memset(dist,0x3f,sizeof dist);
    deque<PII>q;
    q.push_back({0,0});
    dist[0][0]=0;
    while(q.size())
    {
        PII t=q.front();
        q.pop_front();
        int x=t.x,y=t.y;
        if(st[x][y])continue;
        st[x][y]=true;
        for(int i=0;i<4;i++)
        {
            int a=x+dx[i],b=y+dy[i];
            if(a<0||a>n||b<0||b>m)continue;
            int ga=x+ix[i],gb=y+iy[i];
            int u=(g[ga][gb]!=op[i]);
            int d=dist[x][y]+u;
            if(d<dist[a][b])
            {
                dist[a][b]=d;
                if(u)q.push_back({a,b});
                else q.push_front({a,b});
            }
        }
    }
    return dist[n][m];
}

int main()
{
        cin>>n>>m;
        for(int i=0;i<n;i++)scanf("%s",g[i]);
        int d=bfs();
        if(d==0x3f3f3f3f)cout<<"NO SOLUTION"<<endl;
        else cout<<d<<endl;
}
