#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+5;

ll a[N],tr[N],n,m;
void add(int x,int c){
    for(int i=x;i<=n;i+=i&-i)
        tr[i] += c;
}
ll sum(int x){
    ll res = 0;
    for(int i=x;i;i-=i&-i)
        res += tr[i];
    return res;
}

int main(){
    cin>>n>>m;
    int x,l,r;
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        add(i,x);
    }
    while(m--){
        scanf("%d%d%d",&x,&l,&r);
        if(x == 1){
            add(l,r);
        }
        else{
            printf("%lld\n",sum(r)-sum(l-1));
        }
    }
}