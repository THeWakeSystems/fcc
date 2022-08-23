#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
#define ll long long 
#define N 10000
struct op{
    double x , y , ma, mi , v, num;
} s[N] ;
bool cmp(op a, op b){
    if (a.mi == b.mi) return a.ma < b.ma ;
    return a.mi > b.mi ;
}
int main(){
    while(1)
    {
    double n ,r, d = 0;
    cin >> n >> r;
    memset(s,0,sizeof(s) );
    if (n == 0 && r == 0) break;
    for (int i = 1; i <= n; i++){
        cin >> s[i].x >> s[i].y ;
        if (r*r < s[i].y*s[i].y) d = 1;
        else 
        {s[i].mi = -sqrt(r*r - s[i].y*s[i].y) + s[i].x;
        s[i].ma = sqrt(r*r - s[i].y*s[i].y) + s[i].x;
        s[i].v = 0;}
    }
    if (d == 1){
        cout << -1 << endl;
        continue;
    }
    sort( s+1, s+1+(int)n , cmp) ;
    for (int i = 1; i <= n; i++){
        s[i].num = i;
        
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++){
        if (s[i].v == 0 ){
            for (int j = 1; j <= n; j++){
                if (s[j].mi <= s[i].mi && s[j].ma >= s[i].mi){
                    s[j].v = 1;
                }
            }
            ans ++ ;
        }
    }
    printf("%ld\n",ans);
    }
    return 0;
}