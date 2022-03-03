#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <cmath>

using namespace std;


#define rep(i, a, b) for(int i = a; i < b; ++i)
#define per(i, a, b) for(int i = a - 1; i >= b; i--)
#define pb push_back
#define fi first
#define se second
#define endl '\n'
#define IOS {ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);}
typedef long long ll;
typedef pair<int,int> PII;

inline ll read(){
    ll x = 0, w = 1; char c = getchar(); 
    while(c > '9' || c < '0'){ if(c == '-') w = -1 ; c = getchar();}
    while(c >= '0' && c <= '9'){ x = x * 10 + c - '0'; c = getchar(); }
    return x * w;
}


const int inf = 0x3f3f3f3f, N = 2e5 + 10;
ll n, m;
//ll a[N];
char g[1010][1010];
ll dist[1010][1010];
bool st[1010][1010];

int dx[] = {0, -1, 0, 1}, dy[] = {1, 0, -1, 0};

inline void solve()
{
    /* code */
    cin >> n >> m;
    rep(i, 1, n + 1) cin >> g[i] + 1;
    queue<PII> q;
    rep(i, 1, n + 1) rep(j, 1, m + 1) if(g[i][j] == '1') q.push({i, j}), st[i][j] = 1;
    while(q.size()) {
    	PII t = q.front(); q.pop();
    	rep(i, 0, 4) {
    		int a = t.fi + dx[i], b = t.se + dy[i];
    		if(!a || a > n || !b || b > m || st[a][b]) continue;
    		st[a][b] = 1;
    		dist[a][b] = dist[t.fi][t.se] + 1;
    		q.push({a, b});
    	}
    }
    rep(i, 1, n + 1) {
    	rep(j, 1, m + 1) {
    		cout << dist[i][j] << " ";
    	}
    	cout << endl;
    }
    return;
}

int main() 
{
    IOS
    // int T;
    // cin >> T;
    // while(T--)
        solve();
    return 0;
}