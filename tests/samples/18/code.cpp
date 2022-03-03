#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair<int,int>
#define lson rt<<1 , l , mid
#define rson rt<<1|1,  mid + 1 , r
#define  rep( i , a , b ) for(int i = a ; i <= b ; i ++ )
const int N = 5e5+9 ;
template<class T> void re(T &x)
{
    char ch = x = 0 ;
    bool f = 0 ;
    while(!isdigit(ch)) f |= ch == '-', ch = getchar() ;
    while(isdigit(ch)) x = (x<<3)+(x<<1)+ch-'0', ch = getchar() ;
    x = f ? -x : x ;
}
int vis[N];
struct edge
{
    int to , next ;
}e[N<<2];
int top , head[N] , in_s[N] ;
void init()
{
    memset(head , -1 , sizeof head ) ;
    top = 0 ;
}
void add(int u ,int v )
{
    e[top] = {v , head[u]} ;
    head[u] =top++ ;
}
int du[N] ;

void solve()
{
    init() ;
    int n , m , k ;
    re(n) ,re(m) ,re(k) ;
    queue<PII> qu ;
    rep( i , 1 , n ) vis[i] = du[i] = 0 ; 
    rep( i , 1 , k )
    {
        int v  ; re(v) ; vis[v] = 1;
        du[v] = 2 ; 
        qu.push({v,-1}) ;
    }
    rep(i , 1 , m )
    {
        int u , v ;
        re(u) , re(v) ;
        add(u , v ) ;
        add(v , u ) ;
    }
    while(!qu.empty())
    {
        int u = qu.front().first , fa = qu.front().second ; qu.pop() ;
        for(int i = head[u] ; i != -1 ; i = e[i].next )
        {
            int v = e[i].to ;
            if(v == fa ) continue ;
            du[v] ++;
            if(du[v] == 2 )
            {
                qu.push({v,u}) ;
            }
        }
    }
    if(du[1] >= 2 || vis[1]  ) puts("yes") ;
    else puts("no") ;


}
int main()
{
    int t ;
    re(t) ;
    while(t--)
        solve();
    return 0 ;
}

/**
1
5 6 2
3 4
1 2
2
3
1 3
1 5
5 3
3 4
*/
