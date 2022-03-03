/*
 * @Author: Yin ruxiao
 * @Date: 2022-01-21 18:50:41
 * @LastEditTime: 2022-01-21 19:09:14
 * @link: 
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int N=1e5+10;
int n,k;
int a[N];
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int ans=1,last=a[1];
    for(int i=2;i<=n;i++){
        if(abs(a[i]-last)>=k) {
            last=a[i];
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}