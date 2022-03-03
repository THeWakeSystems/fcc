#include<iostream>
using namespace std;
const int N=1e4+4;
int a[N];
int main(){
    int n,k;
    cin >> n >> k;
    int ans=k;
    while(k--){
        int t;
        cin >> t;
        a[t]++;
    }
    for(int i=1;i<=n;i++)
        ans=min(ans,a[i]);
    cout << ans << endl;
    return 0;
}