
#include<stdio.h>
#include<queue>
#include<string.h>
#include<iostream> 
#include<algorithm>
using namespace std;
const int N=900;
string h[N];
int zx[2],zy[2];
struct pos{
	int x,y;
}M,G;
int mov[4][2]={0,1,0,-1,1,0,-1,0};
int n,m;
int Time=0;
int vis[N][N][2];
queue<pair<int,int> >q[2];
int check(pair<int,int>p){
	int x=p.first,y=p.second;
	if(x<0||y<0||x>=n||y>=m) return 0;
	if(h[x][y]=='X'||h[x][y]=='Z') return 0;
	int dis=min(abs(x-zx[0])+abs(y-zy[0]),abs(x-zx[1])+abs(y-zy[1]));
	if(dis<=Time*2) return 0;
	return 1;
}
int bfs(int flag){
	int sum=q[flag].size();
	// cout<<sum<<endl;
	while(sum--){
		pair<int,int>now=q[flag].front();
		q[flag].pop();
		if(check(now)==0) continue;
		
		for( int i=0;i<4;i++){
			pair<int,int>temp=now;
			temp.first+=mov[i][0];
			temp.second+=mov[i][1];
			int x=temp.first,y=temp.second;
			if(check(temp)==1&&vis[x][y][flag]==0){
				if(vis[x][y][!flag]==1) return 1;
				vis[x][y][flag]=1;
				q[flag].push(temp);
			}
		}	
	}
	return 0;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		int cnt=0;
		Time=0;
		memset(vis,0,sizeof(vis));
		while(!q[1].empty()) q[1].pop();
		while(!q[0].empty()) q[0].pop();
		for( int i=0;i<n;i++){
			cin>>h[i];
			for( int j=0;j<m;j++){
				if(h[i][j]=='Z'){
					zx[cnt]=i;
					zy[cnt]=j;
					cnt++;
				}
				if(h[i][j]=='G'){
					G.x=i;
					G.y=j;
				}
				else if(h[i][j]=='M'){
					M.x=i;
					M.y=j;
				}
			}
		}
		//0代表M,可以走三步
		// cout<<zx[0]<<" "<<zx[1]<<endl; 
		q[0].push(make_pair(M.x,M.y));
		q[1].push(make_pair(G.x,G.y));
		vis[M.x][M.y][0]=1,vis[G.x][G.y][1]=1;
		while(!q[0].empty()||!q[1].empty()){
			Time++;
			int res=1;
			for( int i=0;i<3;i++)
				if(bfs(0)==1){
					cout<<Time<<endl;
					goto endd;
				}
			if(bfs(1)==1){
				cout<<Time<<endl;
				goto endd;
			}
		}
		cout<<-1<<endl;
		endd:;

	}
	return 0;
}