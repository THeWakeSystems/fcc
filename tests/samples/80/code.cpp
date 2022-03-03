#include<cstdio>
#include<algorithm>
using namespace std; 
const int inf=100001; 
int n,m; double a[inf],b[inf],l=-1e6,r=1e6; 
int main()
{
    scanf("%d%d",&n,&m); 
    for (int i=1;i<=n;i++) scanf("%lf",&a[i]); 
    while (r-l>1e-5)//精度
    {
        double mi=(l+r)/2; 
        for (int i=1;i<=n;i++) b[i]=a[i]-mi+b[i-1]; 
        double ans=-1e10,num=1e10; 
        for (int i=m;i<=n;i++)
         num=min(num,b[i-m]),ans=max(b[i]-num,ans);
        if (ans>=0) l=mi; else r=mi; 
    }
    printf("%d",int(r*1000));//题目要求 
}