#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <sys/time.h>
using namespace std;

#define int long long
const int MAXN = 50050;
int N, L, dp[MAXN], sum[MAXN], f[MAXN], g[MAXN], h, t, Q[MAXN];

inline double xie(int j1, int j2)
{
	return (double) (dp[j2] + g[j2] - dp[j1] - g[j1]) / (f[j2] - f[j1]);
}
#undef int
int main()
{
    scanf("%d%d", &N, &L);
    for(int i = 1; i <= N; i++)
    {
    	scanf("%d", &sum[i]);
	}
    struct timeval start,end;
    float time_use=0;
    gettimeofday( &start, NULL );
    for(int i = 1; i <= N; i++){
        sum[i] += sum[i - 1];
    	f[i] = sum[i] + i;
    	g[i] = (f[i] + L + 1) * (f[i] + L + 1);
    }
	g[0] = (L + 1) * (L + 1); 
	for(int i = 1; i <= N; i++)
	{
		while(h < t && xie(Q[h], Q[h + 1]) <= 2 * f[i]) h++;
		dp[i] = dp[Q[h]] + (f[i] - f[Q[h]] - L - 1) * (f[i] - f[Q[h]] - L - 1); //更新dp值
		while(h < t && xie(Q[t], i) < xie(Q[t - 1], Q[t])) t--;
		Q[++t] = i;
		
	}
    gettimeofday( &end, NULL );
    time_use=(end.tv_sec-start.tv_sec)*1000000+(end.tv_usec-start.tv_usec);//微秒
    printf("\ntime_use is %f\n",time_use);
	printf("%lld\n", dp[N]);
 	return 0;
}