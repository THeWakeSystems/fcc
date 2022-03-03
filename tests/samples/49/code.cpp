#include<iostream>
using namespace std;
const int N=10000;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        long long a[N];
        long long ans=0,flag=0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(flag<=a[i])flag=a[i];
            ans+=a[i];
        }
        ans=ans-flag;
        cout<<ans<<endl;
    }
    return 0;
}
