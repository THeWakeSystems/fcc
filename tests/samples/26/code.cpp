#include<bits/stdc++.h>
using namespace std;
template<typename T>inline bool read(T&x){
x=0;char c=getchar();int f=1;while(!isdigit(c)&&(c!='-')&&(c!=EOF))c=getchar();
if(c==EOF)return 0;if(c=='-')f=-1,c=getchar();
while(isdigit(c)){x=x*10+(c&15);c=getchar();}x*=f;return 1;
}template<typename T,typename...Args>inline bool read(T&x,Args&...args){bool res=1;res&=read(x);res&=read(args...);return res;}
typedef long long LL;typedef unsigned long long u64;typedef unsigned u32;typedef long double LD;typedef pair<int,int> pii;typedef pair<LL,LL> pll;
#define il inline
#define pln putchar('\n')
#define For(i,a,b)  for(int i=(a),(i##i)=(b);i<=(i##i);++i)
#define Rep(i,n)    for(int i=0,(i##i)=(n);i<(i##i);++i)
#define Fodn(i,a,b) for(int i=(a),(i##i)=(b);i>=(i##i);--i)
const int M=1000000007,INF=0x3f3f3f3f;const long long INFLL=0x3f3f3f3f3f3f3f3fLL;
const int N=1000009;

struct BS{
    u64 a[32];
    BS(){memset(a,0,sizeof a);}
    BS(const BS&b){memcpy(a,b.a,sizeof a);}
    void operator^=(const BS&b){for(int i=0;i<32;++i)a[i]^=b.a[i];}
    bool operator<(const BS&b)const{for(int i=0;i<32;++i)if(a[i]!=b.a[i])return a[i]<b.a[i];return 0;}
    bool none()const{for(int i=0;i<32;++i)if(a[i]!=0)return 0;return 1;}
    void set(int x){a[x/64]|=(1ull<<(63-x%64));}
    int get()const{
        for(int i=0;i<32;++i)if(a[i]!=0){
            for(int j=63;j>=0;--j)if(a[i]>>j&1)return (63-j)+i*64;
        }
        assert(0);return 1;
    }
    void op(int x)const{for(int i=0;i<=x;++i)for(int j=63;j>=0;--j)printf("%d ",a[i]>>j&1);pln;}
    void sw(BS&b){for(int i=0;i<32;++i)swap(a[i],b.a[i]);}
}a[2021];int tot;bool v[2021];

bool b[1009][2][2];
il void mul(bool a[][2],const bool b[][2]){
    bool c[2][2];
    c[0][0]=(a[0][0]&b[0][0])^(a[0][1]&b[1][0]);
    c[0][1]=(a[0][0]&b[0][1])^(a[0][1]&b[1][1]);
    c[1][0]=(a[1][0]&b[0][0])^(a[1][1]&b[1][0]);
    c[1][1]=(a[1][0]&b[0][1])^(a[1][1]&b[1][1]);
    memcpy(a,c,sizeof c);
}
const bool ry[][2]={{0,1},{1,0}},rb[][2]={{1,0},{1,1}},yb[][2]={{1,1},{0,1}};

int n,k,m;
bool ans[2021];

inline void init(){
    read(n,k);For(i,1,n){
        b[i][0][0]=b[i][1][1]=1;
        b[i][0][1]=b[i][1][0]=0;
    }
    while(k--){
        char s[7];scanf("%s",s+1);
        if(s[1]=='m'){
            read(m);tot+=2;
            For(i,1,m){
                int x;read(x);
                if(b[x][0][0])a[tot-1].set(2*x-2);
                if(b[x][1][0])a[tot-1].set(2*x-1);
                if(b[x][0][1])a[tot].set(2*x-2);
                if(b[x][1][1])a[tot].set(2*x-1);
            }
            scanf("%s",s+1);
            if(s[1]=='R'||s[1]=='B')v[tot]=1;
            if(s[1]=='Y'||s[1]=='B')v[tot-1]=1;
        }else if(s[1]=='Y'){
            read(m);For(i,1,m){int x;read(x);mul(b[x],yb);}
        }else if(s[2]=='B'){
            read(m);For(i,1,m){int x;read(x);mul(b[x],rb);}
        }else{
            read(m);For(i,1,m){int x;read(x);mul(b[x],ry);}
        }
    }
}
inline void solve(){
    int t=0;
    while(t<tot){
        int u=t+1;
        for(int i=u+1;i<=tot;++i)if(a[u]<a[i])u=i;
        if(u!=t+1)a[u].sw(a[t+1]),swap(v[u],v[t+1]);
        if(a[t+1].none())break;
        ++t;
        for(int i=1;i<=tot;++i)if(i!=t){
            BS nex(a[i]);nex^=a[t];
            if(nex<a[i]){
                a[i]=nex;v[i]^=v[t];
            }
        }
    }
    for(int i=t+1;i<=tot;++i)if(v[i]){
        puts("NO");exit(0);
    }puts("YES");

    for(int i=1;i<=t;++i)ans[a[i].get()]=v[i];
    For(i,1,n){
        if(ans[2*i-2]){
            if(ans[2*i-1])putchar('B');
            else putchar('Y');
        }else{
            if(ans[2*i-1])putchar('R');
            else putchar('.');
        }
    }pln;
}
signed main(){
    init();
    solve();
    return 0;
}