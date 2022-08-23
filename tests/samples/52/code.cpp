#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 2510;
const int mod = 1e9 + 7;

struct Node{
    LL id, v;
    bool operator<(const Node& t)const{
        return v < t.v;
    }
}alls[N * N];
LL a[N][N];
LL inv[N];
LL vis[N];

LL qmi(LL a, LL b){
    a %= mod;
    LL res = 1;
    while(b){
        if(b & 1) res = (LL)res * a % mod;
        a = (LL)a * a % mod;
        b >>= 1;
    }
    return res;
}
int main(){
    
    int n; scanf("%d", &n);
    for(int i = 1;i <= n; ++ i){
        for(int j = 1;j <= n; ++ j){
            scanf("%lld", &a[i][j]);
            alls[(i - 1) * n + j] = {i, a[i][j]};
        }
    }
    sort(alls + 1, alls + 1 + n * n);
    inv[0] = 1;
    for(int i = 1;i <= n; ++ i) inv[i] = qmi(i, mod - 2);
    
    LL ans = 0;
    LL all_cnt = 0, val = 1;
    for(int i = 1;i <= n * n; ++ i){
        vis[alls[i].id] ++ ;
        if(vis[alls[i].id] == 1) all_cnt ++ ;
        if(vis[alls[i].id] > 1)
            val = val * inv[vis[alls[i].id] - 1] % mod * vis[alls[i].id] % mod;
        if(all_cnt == n){ // 累加答案
            ans += val * 1ll * inv[vis[alls[i].id]] % mod * alls[i].v % mod;
            ans %= mod;
        }
    }
    cout << ans * qmi(qmi(n, n), mod - 2) % mod << endl;
    
    return 0;
}