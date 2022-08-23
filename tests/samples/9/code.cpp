#include<bits/stdc++.h>
using namespace std;
const int maxn=50+5;
char mp[maxn][maxn];
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int vis[4];
int main(){
    int n,m;
    cin>>n>>m;
    int sx,sy,ex,ey;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf(" %c",&mp[i][j]);
            if(mp[i][j]=='S')sx=i,sy=j;
            if(mp[i][j]=='E')ex=i,ey=j;
        }
    }
    string order;
    cin>>order;
    int ans=0;
    for(int i=0;i<4;i++){
        vis[i]=1;
        for(int j=0;j<4;j++){
            if(vis[j])continue;
            vis[j]=1;
            for(int k=0;k<4;k++){
                if(vis[k])continue;
                int p=6-i-j-k;
                int x=sx,y=sy,f=1;
                for(int q=0;q<order.size();q++){
                    if(order[q]=='0')x+=dir[i][0],y+=dir[i][1];
                    if(order[q]=='1')x+=dir[j][0],y+=dir[j][1];
                    if(order[q]=='2')x+=dir[k][0],y+=dir[k][1];
                    if(order[q]=='3')x+=dir[p][0],y+=dir[p][1];
                    if(mp[x][y]=='#'||x<1||x>n||y<1||y>m){f=0;break;}
                    if(x==ex&&y==ey){break;}
                }
                if(f&&x==ex&&y==ey)ans++;
            }
            vis[j]=0;
        }
        vis[i]=0;
    }
    cout<<ans<<endl;
    return 0;
}