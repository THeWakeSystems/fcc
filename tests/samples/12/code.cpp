#include<bits/stdc++.h>
using namespace std;

int n;
long long a[55];//十年OI一场空，不开long long 见祖宗

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i) scanf("%lld", a + i);
    sort(a + 1, a + n + 1);//排序，显然要从小到大分析，否则无法准确考虑连续
    a[n+1] = 1e18;
    long long tot = 0, ans = 1, cnt = 0, base = 1;//tot：用于判断断层，对应最后一段连续区间的右端点的值;cnt 当前状态数轴的覆盖点数;base：当前状态数轴单点对应原数轴区间长度
    for(int i = 1; i <= n + 1; ++ i){
       if(tot >= a[i]){//直接加
           tot += a[i];//右端点更新
           cnt += a[i]/base;//数轴上新增覆盖点数
       }else{//断层
           ans = ans * (cnt + 1);//计算区间大小为a[i]时，每段区间的答案
           tot = a[i]; cnt = 1; base = a[i];//更新右端点，区间大小，覆盖点数
       }
    }
    //准确来说，我们获得了区间大小为1e18，每段区间的答案
    printf("%lld", ans);
    return 0;
}
