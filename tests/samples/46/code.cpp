#include<bits/stdc++.h>
#include <sys/time.h> 
using namespace std;  
typedef long long ll;  
int m,n,k;  
ll f[100100],ans;  
int main()  
{  
//freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int i,j;  
    cin>>m>>n;  
    struct timeval start;
    struct timeval end;
    float time_use=0;
    gettimeofday( &start, NULL );
    k=min(m,n);  
    for(i=k;i;i--)  
    {  
        f[i]=(ll)(m/i)*(n/i);  
        for(j=2;j*i<=k;j++)  
            f[i]-=f[i*j];  
        ans+=f[i]*(i+i-1);  
    }  
    gettimeofday( &end, NULL );
    time_use=(end.tv_sec-start.tv_sec)*1000000+(end.tv_usec-start.tv_usec);//微秒
    
    cout<<ans<<endl;  
    printf("time_use is %f\n",time_use);
    return 0;  
}
