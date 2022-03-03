#include<bits/stdc++.h>
#define int long long
using namespace std;
int bsy(int a,int b){
    return a*b/__gcd(a,b);
}
signed main(){
    std::ios::sync_with_stdio(false);
    int x,y;
    while(cin>>x>>y){
        int cnt=0;
        for(int i=x;i<=y;i+=x)
            for(int j=i;j<=y;j+=x)
                if(__gcd(i,j)==x&&bsy(i,j)==y) cnt+=2;
        cout<<cnt<<endl;
    }
    return 0;
}