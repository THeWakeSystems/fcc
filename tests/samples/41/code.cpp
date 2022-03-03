#include<bits/stdc++.h>
#define int long long
using namespace std;
const long long P=19260817;
const long long INF=(long long)1<<60;
typedef long long LL;
const int N=2e5+10;
const int M=18;
typedef pair<int,int> pii;
int n,ans,a[N],cost[(1<<M)+10][M],d[(1<<M)+10],mark[(1<<M)+10];
bool vis[(1<<M)+10];

inline LL PowMod(LL a, LL b) { LL r=1; while(b) { if(b&1) r=r*a%P; a=a*a%P, b>>=1; } return r; }

void prework()
{
    for (int s = 0; s < (1<<18); ++s) {
        for(int i = 0; i < 18; ++i)
        {
            cost[s][i] = PowMod( max(s,s^(1<<i))%P, 1<<i ) % P + 1;
        }
    }
}

priority_queue<pii> q;
void Dijkstra(int k) {
	while (!q.empty()) q.pop();
	memset(d,0x3f,sizeof(d));
	memset(vis,0,sizeof(vis));
	for (int i=1;i<=n;i++) 
		if (a[i]>>k & 1) {
			q.push(make_pair(0,a[i]));
			d[a[i]]=0;
		}
	while (!q.empty()) {
		pii x=q.top(); q.pop();
		if (mark[x.second] && x.first!=0) ans=min(ans,-x.first);
		if (-x.first>=ans) return;
		if (vis[x.second]) continue;
		vis[x.second]=1;
		
		for (int i=0;i<18;i++) {
			int y=x.second^(1<<i);
			if (d[y]>d[x.second]+cost[x.second][i]) {
				d[y]=d[x.second]+cost[x.second][i];
				q.push(make_pair(-d[y],y));
			}
		}
	}
}

signed main()
{
	prework();

	scanf("%lld",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]),mark[a[i]]=1;
	sort(a+1,a+n+1);
	for (int i=2;i<=n;i++) 
		if (a[i]==a[i-1]) { puts("0"); return 0; }
		
	ans=INF;
	for (int i=0;i<18;i++) Dijkstra(i);
	cout<<ans<<endl;	
	return 0;
}