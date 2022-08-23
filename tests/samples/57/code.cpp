#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1000;
int w[maxn], sw[maxn], f[maxn];
vector<int> G[maxn];
bool b[maxn];
bool find(int u){
    for(int v : G[u]) if(not b[v]){
        b[v] = true;
        if(f[v] == - 1 or find(f[v]))return f[v] = u, true;
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    for(cin >> T; T; T -= 1){
        int n, m, k;
        cin >> n >> m >> k;
        for(int i = 0; i < n * m; i += 1){
            cin >> w[i];
            sw[i] = w[i];
        }
        sort(sw, sw + n * m);
        int L = 0, R = n * m;
        while(L + 1 < R){
            int M = sw[(L + R) >> 1], ans = 0;
            for(int i = 0; i < n * m; i += 1){
                G[i].clear();
                if(w[i] >= M) ans += 1;
                f[i] = -1;
            }
            for(int i = 0; i < n; i += 1)
                for(int j = 0; j < m; j += 1)
                    if((i + j) % 2 == 0 and w[i * m + j] >= M){
                        if(i > 0 and w[(i - 1) * m + j] >= M) G[i * m + j].push_back((i - 1) * m + j);
                        if(i + 1 < n and w[(i + 1) * m + j] >= M) G[i * m + j].push_back((i + 1) * m + j);
                        if(j > 0 and w[i * m + j - 1] >= M) G[i * m + j].push_back(i * m + j - 1);
                        if(j + 1 < m and w[i * m + j + 1] >= M) G[i * m + j].push_back(i * m + j + 1);
                    }
            for(int i = 0; i < n; i += 1)
                for(int j = 0; j < m; j += 1)
                    if((i + j) % 2 == 0 and w[i * m + j] >= M){
                        fill(b, b + n * m, false);
                        if(find(i * m + j)) ans -= 1;
                    }
            if(ans >= k) L = (L + R) >> 1;
            else R = (L + R) >> 1;
        }
        cout << sw[L] << "\n";
    }
    return 0;
}