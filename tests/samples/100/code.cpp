#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define fi first
#define se second
#define debug(x) cerr << #x << " " << x << '\n'
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pli = pair<ll,int>;
const int INF = 0x3f3f3f3f, N = 2e5 + 5;
const ll LINF = 1e18 + 5;
constexpr int mod = 1e9 + 7;
int n, m, c[N], cnt[N], cur;
int s, t, mxlen, son[N], son2[N], len[N], dep[N];
int sta[N], top, ans[N];
int head[N], tot;
struct node
{
	int to, next;
}e[N<<1];
void addedge(int u, int v)
{
	e[++tot].next = head[u];
	e[tot].to = v;
	head[u] = tot;
}
void dfs(int u, int fa, int dis)
{
	if(dis>mxlen) 
	{
		mxlen = dis; 
		t = u;
	}
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(v==fa) continue; 
		dfs(v, u, dis+1);
	}
}
void find()
{
	dfs(1, 0, 0);
	s = t;
	mxlen = t = 0;
	dfs(s, 0, 0); 
}
void dfs2(int u, int fa)
{
	dep[u] = dep[fa] + 1;
	son[u] = son2[u] = 0;
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(v==fa) continue;
		dfs2(v, u);
		if(len[v]>len[son[u]]) son2[u] = son[u], son[u] = v;
		else if(len[v]>len[son2[u]]) son2[u] = v;
	}
	len[u] = len[son[u]] + 1;
}
void add(int u)
{
	cnt[c[u]]++;
	if(cnt[c[u]]==1) cur++;
}
void del(int u)
{
	cnt[c[u]]--;
	if(!cnt[c[u]]) cur--;
}
void dfs3(int u, int fa)
{
	while(top && dep[u]-dep[sta[top]]<=len[son2[u]]) del(sta[top--]);
	add(sta[++top]=u);
	if(son[u]) dfs3(son[u], u);
	while(top && dep[u]-dep[sta[top]]<=len[son[u]]) del(sta[top--]);
	ans[u] = max(ans[u], cur);
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(v==fa || v==son[u]) continue;
		if(sta[top]!=u) add(sta[++top]=u);
		dfs3(v, u);
	}
	if(sta[top]==u) del(sta[top--]);
}
int main()
{
	scanf("%d%d", &n, &m);
	for(int i=1; i<n; i++) 
	{
		int u, v;
		scanf("%d%d", &u, &v);
		addedge(u, v); addedge(v, u);
	}
	for(int i=1; i<=n; i++) scanf("%d", c+i);
	find();
	dfs2(s, 0); dfs3(s, 0);
	dfs2(t, 0); dfs3(t, 0);
	for(int i=1; i<=n; i++) printf("%d\n", ans[i]);
	return 0;
}