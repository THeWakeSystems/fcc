#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 0x3f3f3f3f
#define PII pair<int, int>
#define rep(i, l, r) for (int i = l; i < r; i++)
#define repd(i, l, r) for (int i = l; i <= r; i++)
#define Min(a, b) a > b ? b : a
#define Max(a, b) a > b ? a : b
#define x first
#define y second
#define endl '\n'
using namespace std;
typedef long long LL;
const int N = 1e6 + 10, M = 1010;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int n, m;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int path[N];

bool dfs( int u , int step ){
    if( u > step ) return false;
    if( path[u-1] == n ) return true;

    bool st[M] = {0};
    for( int i = u-1 ; i >= 0 ; i-- )
        for( int j = i ; j >= 0 ; j-- ){
            int s = path[i] + path[j];
            if( s > n || s <= path[u-1] || st[s] ) continue;
            st[s] = true;
            path[u] = s;
            if( dfs( u+1 , step ) ) return true;
        }

    return false;
}

int main()
{
    IOS;
    path[0] = 1;
    while( cin >> n && n ){
        int step = 1;
        while( !dfs(1,step) ) step++;
        rep( i , 0 , step ) cout << path[i] << ' ';
        cout << endl;
    }
    return 0;
}