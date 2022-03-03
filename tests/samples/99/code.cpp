#include<cstdio>
#include<cstdlib>
#include <sys/time.h>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 100005
using namespace std;
typedef long double ldb;
const ldb eps=1e-10;
int bh[maxn],n,s,q[maxn],t[maxn];
ldb x[maxn],a[maxn],b[maxn],y[maxn],f[maxn],rate[maxn],k[maxn];
int compa(const int x,const int y){return k[x]>k[y];}
int comp(const int a,const int b){return fabs(x[a]-x[b])<eps?y[a]<y[b]:x[a]<x[b];}
int dcmp(ldb x){
    return fabs(x)<eps?0:(x<0?-1:1);
}
void turn(int p,ldb fx){
    if(dcmp(f[p]-fx)>=0)return ;
    f[p]=fx;
    y[p]=f[p]/(rate[p]*a[p]+b[p]);
    x[p]=f[p]*rate[p]/(rate[p]*a[p]+b[p]);
}
ldb getk(int n,int m){
    return (y[n]-y[m])/(x[n]-x[m]);
}
void cdq(int xl,int xr){
    if(xl==xr)return ;
    int mid=xl+xr>>1;
    int ptr=xl,rptr=mid+1;
    for(int i=xl;i<=xr;++i){
        if(bh[i]<=mid)t[ptr++]=bh[i];
        else t[rptr++]=bh[i];
    }
    for(int i=xl;i<=xr;++i)bh[i]=t[i];
    cdq(xl,mid);
    int l=1,r=0;
    for(int i=xl;i<=mid;++i){
        while(l<r&&dcmp(getk(bh[i],q[r])-getk(q[r],q[r-1]))>=0)r--;
        q[++r]=bh[i];
    }
    for(int i=mid+1;i<=xr;++i){
        while(l<r&&dcmp(k[bh[i]]-getk(q[l],q[l+1]))<=0)l++;
        turn(bh[i],a[bh[i]]*x[q[l]]+b[bh[i]]*y[q[l]]);
    }
    for(int i=mid+1;i<=xr;++i)turn(i,f[i-1]);
    cdq(mid+1,xr);
    int i=xl,j=mid+1;
    for(ptr=xl;i<=mid&&j<=xr;){
        if(comp(bh[i],bh[j]))t[ptr++]=bh[i++];
        else t[ptr++]=bh[j++];
    }
    for(;i<=mid;)t[ptr++]=bh[i++];
    for(;j<=xr;)t[ptr++]=bh[j++];
    for(int i=xl;i<=xr;++i)bh[i]=t[i];
}
int main(){
//	freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    scanf("%d%d",&n,&s);
    for(int i=1;i<=n;++i)scanf("%Lf%Lf%Lf",&a[i],&b[i],&rate[i]),k[i]=-a[i]/b[i];
    struct timeval start;
    struct timeval end;
    float time_use=0;
    gettimeofday( &start, NULL );
	for(int i=1;i<=n;++i)bh[i]=i,turn(i,s);
    sort(bh+1,bh+n+1,compa);
    cdq(1,n);
    ldb ans=s;
    for(int i=1;i<=n;++i)ans=max(ans,f[i]);
    gettimeofday( &end, NULL );
    time_use=(end.tv_sec-start.tv_sec)*1000000+(end.tv_usec-start.tv_usec);//微秒
    
    printf("%.3lf",(double)ans);
    printf("time_use is %f\n",time_use);
}
