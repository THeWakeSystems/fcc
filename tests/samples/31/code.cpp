#include<cstdio>
#include <sys/time.h> 
using namespace std;
long long m,a,c,x0,n,g;
struct matrix
{
    long long m[2][2];
};
matrix I=
{
    1,0,
    0,1
};
long long mul(long long x,long long y)
{
    long long ans=0;
    while (y)
    {
        if (y&1)ans=(ans+x)%m;
        x=2*x%m;
        y/=2;
    }
    return ans;
}
matrix operator *(matrix a,matrix b)
{
    matrix c;
    for (int i=0;i<=1;i++)
    {
        for (int j=0;j<=1;j++)
        {
            c.m[i][j]=0;
            for (int k=0;k<=1;k++)(c.m[i][j]+=mul(a.m[i][k],b.m[k][j]))%=m;
        }
    }
    return c;
}
matrix power(matrix a,long long k)
{
    matrix ans=I,p=a;
    while (k)
    {
        if (k&1)ans=ans*p;
        p=p*p;
        k/=2;
    }
    return ans;
}
int main()
{
//	freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    scanf("%lld%lld%lld%lld%lld%lld",&m,&a,&c,&x0,&n,&g);
    struct timeval start;
    struct timeval end;
    float time_use=0;
    gettimeofday( &start, NULL );
    matrix A=
    {
        a,0,
        c,1
    };
    matrix answer=power(A,n);
    long long k=(mul(x0,answer.m[0][0])+answer.m[1][0])%m;
    gettimeofday( &end, NULL );
    time_use=(end.tv_sec-start.tv_sec)*1000000+(end.tv_usec-start.tv_usec);//微秒
    
    printf("%lld",k%g);
    printf("time_use is %f\n",time_use);
    return 0;
}
