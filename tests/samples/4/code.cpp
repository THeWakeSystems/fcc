#include<iostream>
#include<algorithm>
using namespace std;
int a[105],d[105],stone[350000];
int f[350000]; //压缩路径后f[]就不必开10^9那么大了 
int main()
{
    int l,s,t,m;
    cin>>l>>s>>t>>m;
    for (int i=1;i<=m;i++)
        cin>>a[i];
    sort(a+1,a+m+1); //输入石子坐标可能无序 
    for (int i=1;i<=m;i++)
        d[i]=(a[i]-a[i-1])%2520; //要对1~10的最小公倍数取余，压缩路径的核心
    for (int i=1;i<=m;i++)
    {
        a[i]=a[i-1]+d[i];
        stone[a[i]]=1; //此处有石子，标记 
    }
    l=a[m]; //压缩路径后的总长度 
    for (int i=0;i<=l+t;i++) f[i]=m; //f[i]表示到位置i最少能踩到的石子数  
    f[0]=0;
    //以上是初始化，接下来是动归
    for (int i=1;i<=l+t;i++)
        for (int j=s;j<=t;j++)
        {
            if (i-j>=0)
                f[i]=min(f[i],f[i-j]); //状态转移方程 
            f[i]+=stone[i];
        }
    int ans=m;
    for (int i=l;i<l+t;i++) ans=min(ans,f[i]);
    cout<<ans<<endl;
    return 0;
}
