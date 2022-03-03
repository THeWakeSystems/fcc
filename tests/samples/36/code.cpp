#include<bits/stdc++.h>
typedef long long ll;
int n,m;
int matrex[105][105];
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m;
    memset(matrex, 0, sizeof(matrex));
    while (m--) {
        int a, b;
        std::cin >> a >> b;
        matrex[a][b] = 1;
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (matrex[i][k] && matrex[k][j])
                    matrex[i][j] = 1;
            }
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++) {
        bool flag=true;
        for(int j=1;j<=n;j++) {
            if(j!=i&&!matrex[i][j]&&!matrex[j][i]) {
                flag=false;
            }
        }
        cnt+=flag;
    }
    std::cout<<cnt<<std::endl;
    return 0;
}