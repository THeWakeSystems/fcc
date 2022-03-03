#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <sstream>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#define ll long long

using namespace std;

ll n,m,l1,r1,l2,r2,x;

struct node{
    ll num;
    ll id;
    bool operator < (const node &n) const{
        if(num==n.num) return id<n.id;
        return num<n.num;
    }

}arr[110000];

ll get(ll l,ll r,ll x){
    ll s = lower_bound(arr+1,arr+n+1,node{x,l})-arr;
    ll e = upper_bound(arr+1,arr+n+1,node{x,r})-arr;
    return e-s;
//     ll ans = 0;
//     while(l<=r){
//         ll t = lower_bound(arr+1,arr+n+1,node{x,l})-arr;
//         if(arr[t].num==x) ans++;
//         l = arr[t].id+1;
//     }
//     return ans;
}

int main()
{       
    cin >> n >> m;

    for(int i = 1;i <= n;++i){
        cin >> arr[i].num;
        arr[i].id = i;
    }
    sort(arr+1,arr+n+1);

    for(int i = 1;i <= m;++i){
        cin >> l1 >> r1 >> l2 >> r2 >> x;
        if(l1>r1) swap(l1,r1);
        if(l2>r2) swap(l2,r2);
        ll t1 = get(l1,r1,x);
        ll t2 = get(l2,r2,x);
        cout << t1%20180623 << endl << t2%20180623 << endl << (t1*t2)%20180623 << endl;
    }

    return 0;
}

// 10 1
// 2 1 3 2 2 2 5 2 1 0
// 1 5 2 4 2