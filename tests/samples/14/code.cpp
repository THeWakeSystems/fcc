#include<stdio.h>
#include<algorithm>
#include<queue>
#include <sys/time.h> 
#define ll long long
#define N 100005
using namespace std;
char buf[1<<20],*p1,*p2;
#define GC (p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?0:*p1++)
inline void _R(int &x)
{
	char t=GC;
	while(t<48||t>57) t=GC;
	for(x=0;t>47&&t<58;t=GC) x=(x<<3)+(x<<1)+t-48;
}
struct node
{
	int val,id;
};
bool operator<(node a,node b)
{
	return a.val<b.val;
}
priority_queue<node>Q;
int sum,n,m,q,a[N],s[N],c[N],x[N],fa[N],cnt[N],qry[N],Max;
ll ans[N*10];
int GF(int x)
{
	return x==fa[x]?x:fa[x]=GF(fa[x]);
}
int main()
{
//	freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
	int i;_R(n);_R(m);_R(q);
	for(i=1;i<=n;i++)
	{
		_R(a[i]);_R(s[i]);_R(c[i]);_R(x[i]);
		Q.push((node){a[i]+s[i],i});
	 } 
	 for(i=1;i<=q;i++)
	 {
	 	_R(qry[i]);
	 	Max=max(Max,qry[i]);
	 }
	 struct timeval start;
    struct timeval end;
    float time_use=0;
    gettimeofday( &start, NULL );
	 for(i=1;i<=Max;i++) fa[i]=i,cnt[i]=m;
	 while(Q.size())
	 {
	 	node tmp=Q.top();Q.pop();
	 	int t=x[tmp.id]?(c[tmp.id]-1)/x[tmp.id]+1:Max;
	 	if(t>Max) t=Max;
	 	t=GF(t);if(!cnt[t]) continue;
	 	cnt[t]--;sum++;c[tmp.id]--;
	 	if(!cnt[t]) fa[t]=fa[t-1];
	 	ans[sum]=ans[sum-1]+tmp.val;
	 	if(c[tmp.id]) Q.push((node){a[tmp.id],tmp.id});
	 }
	 gettimeofday( &end, NULL );
    time_use=(end.tv_sec-start.tv_sec)*1000000+(end.tv_usec-start.tv_usec);//微秒
    
	 for(i=1;i<=q;i++) printf("%lld\n",ans[min(sum,qry[i]*m)]);
	 printf("time_use is %f\n",time_use);
}
