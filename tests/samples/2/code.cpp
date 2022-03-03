#include<bits/stdc++.h>
using namespace std;
struct tEdge{int v,w,pre;}E[10001];int head[101],tot;
void AddEdge(int u,int v,int w){E[++tot].v=v,E[tot].w=w,E[tot].pre=head[u],head[u]=tot;}
int n,p,c[101],u[101],w[10001],cnt[101],vis[101];
int DFS(int p){
	if(vis[p])return c[p];
	vis[p]=true;
	for(int i=head[p];i;i=E[i].pre)
		c[p]+=DFS(E[i].v)*E[i].w;
	if(c[p]>0)return c[p];
	else return 0;
}
int main(){
	cin>>n>>p;
	for(int i=1,u;i<=n;i++){
		cin>>c[i]>>u;
		if(!c[i])c[i]-=u;
	}
	for(int i=1,u,v,w;i<=p;i++){
		cin>>u>>v>>w;
		AddEdge(v,u,w);
		cnt[u]++;
	}
	bool flag=false;
	for(int i=1;i<=n;i++)
		if(cnt[i]==0)
			if(DFS(i)>0)cout<<i<<" "<<DFS(i)<<endl,flag=true;
	if(!flag)cout<<"NULL"<<endl;
	return 0;
}
