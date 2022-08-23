#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

typedef long long ll;

const int mod=1e9+7,N=1e6+10;
int fact[N],infact[N];

ll qmi(int a, int k, int p){
    int res = 1;
    while(k){
        if(k & 1) res = (ll) res * a % mod;
        a = (ll) a * a % p;
        k >>= 1;
    }
    return res;
}

void init()
{
    fact[0] = infact[0] = 1;
    for(int i = 1; i < N; i ++){
        fact[i] = (ll)i * fact[i - 1] % mod;
        infact[i] = (ll)infact[i - 1] * qmi(i, mod - 2, mod) % mod;
    }
}

ll C(int a,int b)
{
    if(a<b) return 0;
    if(a==b) return 1;
    return (ll)fact[a] * infact[a - b] % mod * infact[b] % mod;
}

int main()
{
    init();
    int n,a,b;
    cin>>n>>a>>b;
    ll m=(ll)n*(n-1)/2;
    ll res=C(m,a)*C(m-a,b)%mod;
    ll sum=C(m,a)*C(m,b)%mod;
//     cout<<"res = "<<res<<" sum = "<<sum<<endl;
    cout<<((sum-res)%mod+mod)%mod<<endl;
}