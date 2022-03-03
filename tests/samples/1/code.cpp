#include<iostream>
#include<cstring>//头文件
using namespace std;
int a[17],n,k,ans[17],maxn;//a【】表示这种方法的邮票，ans【】表示如今取得的解即要输出的
int dp(int t,int mx){
    int f[50000];//f[i]为拼i所需的最少数的个数
    f[0]=0;//边界
    for(int i=1;i<=a[t]*n;i++)
      f[i]=50000;//赋初值赋一个尽可能地大就可以了
    for(int i=1;i<=t;i++)            //从第一位找到目前的位数把所有已找的邮票都枚举 
      for(int j=a[i];j<=a[t]*n;j++)   //因为不可能找到比自己小的数，所以从自己开始找 
        f[j]=min(f[j],f[j-a[i]]+1);    //比较上几次已找到的最小需要位数和即将要找的相比较，取较小值 
for(int i=1;i<=a[t]*n;i++)
      if(f[i]>n)//如果所需最小的个数大于n就意味着这种情况不符合，但f【i-1】是符合的不然f【i-1】就会判断所以不符合返回i-1
        return i-1;
    return a[t]*n;//如果到a【t】*n的f【i】都满足意味着能取到的最大连续数就是a【t】*n
}
void dfs(int t,int mx){              // 为什么全部找完：因为多几张邮票肯定比少几张邮票可能的情况多，所以全部找完是最好的  
    if(t==k+1){        //如果所有邮票数已经找完，那么就和 maxn比较谁更大   
        if(mx>maxn){
            maxn=mx;
            for(int i=1;i<=t-1;i++)
              ans[i]=a[i];} //保存所需要的邮票面值  
        return;
        }
    for(int i=a[t-1]+1;i<=mx+1;i++){  //继续找：为了避免重复，下一张邮票要比上一张邮票大，所以上边界是a[t-1]+1，同时它不能比最大连续值+1还大，不然最大连续值的下一个数就永远连不起来了 
      a[t]=i;
      int x=dp(t,mx);   //动归寻找此时的最大连续数 
      dfs(t+1,x);
    }
}
int main(){
    cin>>n>>k;
    dfs(1,0);  //先从第一张开始找，第一张前面没有数，所以所连续的最大数为 0 
    for(int i=1;i<=k;i++)//输出 注意打空格以及大写换行即可
      cout<<ans[i]<<" ";
    cout<<endl;
    cout<<"MAX="<<maxn<<endl;
    return 0;
}
