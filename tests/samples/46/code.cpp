#include <bits/stdc++.h>
#define N 1000000007
using namespace std;
long long f(long long a,long long n)
{
    long long s=1;
    for(long long i=0;i<n;i++)
        s=s*a%998244353;
    return s%998244353;
}
int main()
{
   long long n,t,i,s=0,p=1,k=1;
    cin>>t;
  while(t--)
  {
      s=0;p=0;k=1;
      cin>>n;
      for(i=1;i<=n;i++)
      {
          s=(s+i)%998244353;
          p=(p+i)%998244353;
      }
      for(i=1;i<=n;i++)
      {
          k=k*i%998244353;
      }
      k=f(k,2*n);
      k=k%998244353;
          cout<<s*p%998244353<<' '<<k<<'\n';
  }
}