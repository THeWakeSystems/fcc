#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    long long  i,j,sum=0,dd;
    cin>>n;
    cin>>dd;
    int a[100005];
    int b[100005];
    for(i=1;i<n;i++)
   scanf("%d",&a[i]);
    for(i=1;i<n;i++)
    scanf("%d",&b[i]);

    
    for(i=1;i<n;i++)
    {
            while(a[i]>=dd&&dd!=0)
            {a[i]-=b[i];sum++;dd--;}
    }
 if(dd<=0)
   cout<<-1;
    else cout<<sum;
}