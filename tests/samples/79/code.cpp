#include<iostream>
using namespace std;
int z;
int m;
int h;
long long mul(long long  a,long long b,long long c)
{
    long long ans=1%c;//这里也要加求余
    for(;b;b>>=1)
    {
        if(b&1) ans=(ans*a)%c;
        a=a*a%c;

    }
    return ans;
}
int main()
{
   cin>>z;

   while(z--)
   {
       cin>>m;
       cin>>h;
       long long an=0;
       long long a,b;
       for(int i=1;i<=h;i++)
       {
           cin>>a>>b;
           an=(an+mul(a,b,m))%m;
       }
       
       cout<<an<<endl;
   }
    
    

    return 0;
}