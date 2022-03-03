#include<bits/stdc++.h>
using namespace std;
int n,k,x,y,z,cnt,ns=0x3f3f3f3f,root=0,sz,head[100001],d[100001],tmp[100001],siz[100001],ans,tot,vis[100001];
struct Node{int to,nxt,w;}a[200001];
void ad(int x,int y,int z){a[++cnt]=(Node){y,head[x],z};head[x]=cnt;}
void find_root(int u,int fa){
	siz[u]=1;
	int res=0;
	for(int i=head[u];i>0;i=a[i].nxt){
		if(vis[a[i].to]||fa==a[i].to)continue;
		find_root(a[i].to,u);
		siz[u]+=siz[a[i].to];
		res=max(res,siz[a[i].to]);
	}
	res=max(res,sz-siz[u]);
	if(res<ns)ns=res,root=u;
}
void get_dis(int u,int fa){
	tmp[++tot]=d[u];
	for(int i=head[u];i>0;i=a[i].nxt){
		if(vis[a[i].to]||a[i].to==fa)continue;
		d[a[i].to]=d[u]+a[i].w;
		get_dis(a[i].to,u);
	}
}
int qj(int u,int dis){
	d[u]=dis;tot=0;
	get_dis(u,u);
	sort(tmp+1,tmp+1+tot);
	int l=1,r=tot,res=0;
	for(;l<r;l++){while(tmp[l]+tmp[r]>k)r--;if(l<r)res+=(r-l);}
	return res;
}
void dfs(int u){
	vis[u]=1;
	ans+=qj(u,0);
	for(int i=head[u];i>0;i=a[i].nxt){
		if(vis[a[i].to])continue;
		ans-=qj(a[i].to,a[i].w);
		ns=0x3f3f3f3f,root=0,sz=siz[a[i].to];
		find_root(a[i].to,0);
		dfs(root);
	}
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	while(cin>>n>>k&&n&&k){
		for(int i=0;i<=n+1;i++)vis[i]=0,head[i]=-1;
		ans=cnt=0;
		for(int i=1;i<n;i++)cin>>x>>y>>z,ad(x,y,z),ad(y,x,z);
		dfs(1);
		cout<<ans<<"\n";
	}
	return 0;
}