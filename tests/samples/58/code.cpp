#include <bits/stdc++.h>
using namespace std;
using U32 = unsigned int;
const U32 P = 1e8 + 7;
inline U32 add_mod(U32 a, U32 b) {
    U32 ret = a + b;
    return ret < P ? ret : ret - P;
}
inline U32 sub_mod(U32 a, U32 b) {
    U32 ret = a - b;
    return a < b ? ret + P : ret;
}
inline U32 mul_mod(U32 a, U32 b) { return (long long)a * b % P; }
const U32 maxn = 100005;
U32 n_inv[maxn] = {0, 1};
U32 fac[maxn] = {1, 1};
U32 f_inv[maxn] = {1, 1};
inline void pre() {
    for (U32 i = 2; i < maxn; ++i) {
        n_inv[i] = mul_mod(n_inv[P % i], P - P / i);
        fac[i] = mul_mod(fac[i - 1], i);
        f_inv[i] = mul_mod(f_inv[i - 1], n_inv[i]);
    }
}
inline U32 comb(U32 n, U32 m) { return mul_mod(fac[n], mul_mod(f_inv[m], f_inv[n - m])); }
int main() {
    pre();
    U32 t, n, m, k;
    scanf("%u", &t);
    while (t--) {
        scanf("%u%u%u", &n, &m, &k);
        U32 ans = 0;
        for (U32 i = 0; i <= m && i * k <= n - m; ++i) {
            if (i & 1)
                ans = sub_mod(ans, mul_mod(comb(m, i), comb(n - i * k - 1, m - 1)));
            else
                ans = add_mod(ans, mul_mod(comb(m, i), comb(n - i * k - 1, m - 1)));
        }
        printf("%u\n", ans);
    }
}