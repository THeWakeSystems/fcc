#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
#define ll long long 
#define N 1000000
ll q[N], sum[N] ,a[N];
int main(){
    ll n , m;
    cin >> n >> m;
    for (ll i = 1; i <= n; i++){
        cin >> q[i];
        sum[i] = sum[i - 1] + q[i] ;
    }
    ll l = 1 , r = 1 ,ans = 0;
    a[1] = 0 ;
    for (ll i = 1; i <= n; i++){
        while(l <= r && a[l] < i - m) l++;
        ans = max(ans , sum[i] - sum[a[l]]);
        while (l <= r && sum[a[r]] >= sum[i]) r--;
        a[++r] = i ;
    }
    cout << ans ;
    return 0;
}