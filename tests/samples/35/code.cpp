#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL mod = 998244353;

LL n, k;
LL qmi(LL a, LL b){
    LL res = 1;
    while(b){
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
int main(){
    
    cin >> n >> k;
    LL ans = 0;
    
    if(n == 1 || k == 1) ans = 0;
    else ans = (qmi(n - 1, k) + (n - 1) * qmi(-1, k)) * qmi(n, mod - 2) % mod;
    cout << (ans % mod + mod) % mod << endl;
    
    return 0;
}