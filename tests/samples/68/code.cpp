#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
using ll = long long;

const int N = 4;
int n, m;
int f[N][N] = {1, 1, 1, 0}; // fn fn+1 sn pn
int a[N][N] = {
    {0, 1, 0, 0},
    {1, 1, 1, 0},
    {0, 0, 1, 1},
    {0, 0, 0, 1},
};

void mul(int c[N][N], int a[N][N], int b[N][N])
{
    int t[N][N];
    memset(t, 0, sizeof t);
    for (int i = 0; i < N; i ++ )
        for (int j = 0; j < N; j ++ )   
            for (int k = 0; k < N; k ++ )
                t[i][j] = (1ll * t[i][j] + a[i][k] * b[k][j]) % m;
    memcpy(c, t, sizeof t);
}

int main()
{
    cin >> n >> m;
    int k = n - 1;
    while (k)
    {
        if (k & 1) mul(f, f, a);
        mul(a, a, a);
        k >>= 1;
    }
    
    printf("%d\n", ((1ll * n * f[0][2] - f[0][3]) % m + m) % m);
    
    return 0;
}
