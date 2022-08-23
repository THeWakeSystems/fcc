#include <bits/stdc++.h>
#define ll long long
#define pir pair<int,int>
const int N = 5e5+7;
const int mod = 1e9+7;
const ll ds = 1e15;
const double eps = 1e-8;
 
using namespace std;

void solve(){
    double x,y,t,fz,fm;
    scanf("%lf%lf%lf",&x,&y,&t);
    if(y-x-t < eps){
        printf("1.00000\n");
        return;
    }
    fm = (y-x)*(y-x);
    fz = fm-(y-x-t)*(y-x-t);
    double ans = fz/fm;
    printf("%.5f\n",ans);
}

int main(){
    int t;
    cin >> t;
    while(t--)
        solve();
    system("paues");
    return 0;
}
