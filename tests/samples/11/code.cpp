#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
const int Max=2000000000;
int n,i,j,k,m,ans,a[40005];
int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    a[0]=Max;
    a[n+1]=Max;
    m=n;
    for(i=1;i<n;i++)
    {
        k=0;
        for(j=1;j<=m;j++)
            if(a[j-1]<=a[j+1])
        {
            k=j;
            break;
        }
        a[k-1]+=a[k];
        for(j=k;j<m;j++)
            a[j]=a[j+1];
        k--;
        ans+=a[k];
        while(k>0&&a[k-1]<=a[k])
        {
            swap(a[k-1],a[k]);
            k--;
        }
        a[m]=Max;
        m--;
    }
    cout<<ans;
    return 0;
}