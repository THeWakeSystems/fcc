#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
#define ll long long 
#define ull unsigned long long 
#define N 1000010
char s[N] ;
ull f[N], p[N] ;
int main(){
    int q;
    scanf("%s",s) ;
    //cout << s << endl;
    cin >> q;
    p[0] = 1;
    for (int i = 1; i <= strlen(s); i++) {
        f[i] = f[i - 1] * 131 + (s[i - 1] - 'a' + 1) ;
        p[i] = p[i - 1] * 131 ;
    }
    for (int i = 1; i <= q; i++){
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2 ;
        if (f[r1] - f[l1 - 1] * p[r1 - l1 + 1] == f[r2] - f[l2 - 1] *p[r2 - l2 + 1]) {
            cout <<"Yes" << endl;
        }
        else cout <<"No" << endl;
    }
    return 0;
}