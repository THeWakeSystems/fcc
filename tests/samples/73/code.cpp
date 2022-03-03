#include <iostream>
#define ll long long

using namespace std;

const int mod = 1000003;
int n, l, r, t;

ll qp(ll a, ll n){
    ll res = 1;
    while(n){
        if(n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    
    return res;
}

ll c(ll a, ll b){
    if(a < b) return 0;
    
    ll up = 1;
    ll down = 1;
    for(int i = a, j = 1; j <= b; j ++ , i -- ){
        up = up * i % mod;
        down = down * j % mod;
    }
    
    return up * qp(down, mod - 2) % mod;
}
ll lucass(ll a, ll b){
    if(a < mod && b < mod) return c(a, b);
    
    return lucass(a % mod, b % mod) * c(a / mod, b / mod) % mod;
}
int main(){
    
    cin >> t;
    
    while(t -- ){
        cin >> n >> l >> r;
        
        cout << (lucass(r - l + n + 1, r - l + 1) - 1 + mod) % mod << endl;
    }
    
    return 0;
}