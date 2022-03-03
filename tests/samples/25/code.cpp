#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define ld long double
#define all(x) x.begin(), x.end()
#define eps 1e-6
using namespace std;
const int maxn = 50 + 9;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll n, m, h;
char mp[maxn][maxn];
bool vis[maxn][maxn], ok[maxn][maxn];
vector <pair<int,int> > v;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
struct node{
	int x, y, step;
};
int ans = inf;

bool check(int x, int y){
	if(x < 1 || y < 1 || x > n || y > m) return 0;
	return 1;
}
void bfs()
{
	queue<node> q;
	q.push({1, 1});
	vis[1][1] = 1;
	while(!q.empty())
	{
		node now = q.front();q.pop();
		if(now.x == n && now.y == m){
			ans = min(ans, now.step);
			return; 
		}
		for(int i = 0; i < 4; ++i){
			int xx = now.x + dx[i];
			int yy = now.y + dy[i];
			if(check(xx, yy) && !vis[xx][yy])
			{
				if(mp[xx][yy] == '.' || mp[xx][yy] != '*' && ok[xx][yy]){
					vis[xx][yy] = 1;
					q.push({xx, yy, now.step + 1});
				}
			}
		}
	}
}
void work()
{
	cin >> n >> m >> h;
	for(int i = 1; i <= n; ++i) cin >> (mp[i] + 1);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			if(mp[i][j] >= '1' && mp[i][j] <= '9')
				v.push_back({i, j});
	for(int i = 0; i < (1 << v.size()); ++i){
		memset(vis, 0, sizeof(vis));
		memset(ok, 0, sizeof(ok));
		int sum = 0;
		for(int j = v.size() - 1; j >= 0; --j) if(i & (1 << j))
			ok[v[j].first][v[j].second] = 1, sum += mp[v[j].first][v[j].second] - '0';
		if(sum >= h) continue;
		bfs();
	}
	cout << (ans == inf ? -1 : ans);
}

int main()
{
	ios::sync_with_stdio(0);
//	int TT;cin>>TT;while(TT--)
	work();
	return 0;
}
