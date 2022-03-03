#include <iostream>
using namespace std;
int main()
{
 long long a,b,p;
    cin>>a>>b>>p;
    long long ans=0;
    while(b)
    {
        if(b&1) ans=(ans+a)%p;
        a=a*2%p;
        b>>=1;
    }
    cout<<ans;
    return 0;
}