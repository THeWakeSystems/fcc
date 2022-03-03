#include<stdio.h>
#include<cstring>
#include <sys/time.h> 
#include<algorithm>
#define loss(a) memset(a, -10, sizeof(a))
using namespace std;
const int maxn = 410;
struct point{int l, r;}a[maxn];
int n, cnt, top, ans, q[maxn];
int f[maxn][maxn], c[maxn][maxn], g[maxn][maxn], num[maxn][maxn];
int main(){
//	freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    scanf("%d", &n);
    loss(f), loss(g), loss(c);
    for(int i = 1; i <= n; ++i){
        scanf("%d%d", &a[i].l, &a[i].r);
        a[i].r += a[i].l;
        q[++cnt] = a[i].l, q[++cnt] = a[i].r;
    }
    
struct timeval start;
    struct timeval end;
    float time_use=0;
    gettimeofday( &start, NULL );
    sort(q + 1, q + cnt + 1);
    top = unique(q + 1, q + cnt + 1) - q - 1;
    for(int i = 1; i <= n; ++i){
        a[i].l = lower_bound(q + 1, q + top + 1, a[i].l) - q;
        a[i].r = lower_bound(q + 1, q + top + 1, a[i].r) - q;
    }
    for(int i = 1; i <= top; ++i){
        for(int j = 1; j <= n; ++j)
            if(a[j].l >= i) ++num[i][a[j].r];
        for(int j = i + 1; j <= top; ++j)
            num[i][j] += num[i][j - 1];
    }
    f[1][0] = num[1][1], f[1][num[1][1]] = 0;
    for(int i = 2; i <= top; ++i)
        for(int j = 0; j <= n; ++j)
            for(int k = 1; k < i; ++k){
                f[i][j] = max(f[i][j], max(f[k][j] + num[k][i], f[k][j - num[k][i]]));
    }
    for(int i = 0; i <= n; ++i) ans = max(ans, min(i, f[top][i]));
    
    printf("%d\n", ans);
    g[top][0] = num[top][top], g[top][num[top][top]] = 0;
    for(int i = top - 1; i; --i)
        for(int j = 0; j <= n; ++j)
            for(int k = i + 1; k <= top; ++k)
                g[i][j] = max(g[i][j], max(g[k][j] + num[i][k], g[k][j - num[i][k]]));
    for(int i = 1; i <= top; ++i)
        for(int j = i; j <= top; ++j){
            for(int x = 0, y = n; x <= n; ++x){
                while(y >= 0 && x + y > num[i][j] + f[i][x] + g[j][y]) y--;
                if(y >= 0) c[i][j] = max(c[i][j], x + y);
            }
        }
    gettimeofday( &end, NULL );
    time_use=(end.tv_sec-start.tv_sec)*1000000+(end.tv_usec-start.tv_usec);//微秒
    
    for(int i = 1; i <= n; ++i){
        ans=0;
        for(int j = 1; j <= a[i].l; ++j)
            for(int k = a[i].r; k<=top; ++k)
                ans=max(ans, c[j][k]);
        printf("%d\n",ans);
    }
    printf("time_use is %f\n",time_use);
}
