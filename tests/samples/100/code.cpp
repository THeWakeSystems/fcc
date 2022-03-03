#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include <sys/time.h>
#define inf 0x7f7f7f7f
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
inline char gc(){
	static char buf[1000000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;
}
inline int frd(){
	int x=0,f=1;char ch=gc();
	for (;ch<'0'||ch>'9';ch=gc())	if (ch=='-')    f=-1;
	for (;ch>='0'&&ch<='9';ch=gc())	x=(x<<1)+(x<<3)+ch-'0';
	return x*f;
}
inline int read(){
	int x=0,f=1;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar())	if (ch=='-')	f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar())	x=(x<<1)+(x<<3)+ch-'0';
	return x*f;
}
inline void print(int x){
	if (x<0)    putchar('-'),x=-x;
	if (x>9)	print(x/10);
	putchar(x%10+'0');
}
const int N=1e2;
const int dx[8]={-2,-2,-1,-1,1,1,2,2};
const int dy[8]={-1,1,-2,2,-2,2,-1,1};
int dis[N+10][N+10];
struct S1{
	int x,y;
	void insert(int _x,int _y){x=_x,y=_y;}
}h[N*N+10];
bool in_map(int x,int y){return x>0&&y>0&&x<=100&&y<=100;}
void bfs(int x,int y){
	int head=1,tail=1;
	memset(dis,255,sizeof(dis));
	h[head].insert(x,y),dis[x][y]=0;
	for (;head<=tail;head++){
		int Nx=h[head].x,Ny=h[head].y;
		for (int k=0;k<8;k++){
			int tx=Nx+dx[k],ty=Ny+dy[k];
			if (in_map(tx,ty)&&!~dis[tx][ty]){
				dis[tx][ty]=dis[Nx][Ny]+1;
				h[++tail].insert(tx,ty);
			}
		}
	}
}
int main(){
	int ox=read(),oy=read(),ex=read(),ey=read(),Ans=0;
    struct timeval start,end;
    float time_use=0;
    gettimeofday( &start, NULL );
	int x=abs(ox-ex),y=abs(oy-ey);
	while (x+y>50){
		if (x<y)	swap(x,y);
		if (x-4>y<<1)	x-=4;
		else	x-=4,y-=2;
		Ans+=2;
	}
	x+=50,y+=50;
	bfs(x,y);
    gettimeofday( &end, NULL );
    time_use=(end.tv_sec-start.tv_sec)*1000000+(end.tv_usec-start.tv_usec);//微秒
    printf("\ntime_use is %f\n",time_use);
	printf("%d\n",Ans+dis[50][50]);
	return 0;
}