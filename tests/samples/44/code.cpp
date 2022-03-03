#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxnum=100005;
typedef long long ll;
int n,m;
int a[maxnum];
int b[maxnum];
ll sum[maxnum];
int gcd(int a,int b)
{
    if(a%b==0)
        return b;
    else
        return gcd(b,a%b);
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        //sum=0;
        int x;
        memset(a,0,sizeof(a));
        memset(sum,0,sizeof(sum));
        fill(b,b+maxnum,-1);
        for(int i=0; i<m; i++)
        {
            cin>>x;
            b[i]=x;
            a[x-1]=1;
        }
        sort(b,b+m);
        //cout<<"Yes"<<endl;
        // cout<<m/gcd(n,m)<<"/"<<n/gcd(n,m)<<endl;
        printf("%d/%d\n",m/gcd(n,m),n/gcd(n,m));
        bool flag=false;
        int k=1;
        // for(k=1;flag!=true;k++)
        {
            // cout<<"Yes"<<endl;
            // sum=0;
            for(int i=0; i<m; i++)
            {
//               if(i<m-1&&b[i+1]-b[i]>k)
//               {
//                   sum++;
//               }
//               else if(i==m-1&&n-b[i]+b[0]-1>=k)
//                sum++;
                if(i<m-1)
                {
                    int len=b[i+1]-b[i];
                    for(int j=1; j<len; j++)
                    {
                        sum[j]++;
                    }
                }
                else
                {
                    int len=n-b[i]+b[0];
                    for(int j=1; j<len; j++)
                        sum[j]++;
                }
            }
            // cout<<endl;
            for(int i=1; i<n; i++)
            {
                if(sum[i]==0)
                    printf("0\n");
                else
                {
                    // cout<<sum/gcd(n,sum)<<"/"<<n/gcd(n,sum)<<endl;
                    // printf("%d/%d\n",sum/gcd(n,sum),n/gcd(n,sum));
                    //cout<<n<<" "<<sum<<" "<<gcd(n,sum)<<endl;
                    int temp=gcd(n,sum[i]);
                    //cout<<temp<<endl;
                    //printf("%d\n",temp);
                    int temp1=sum[i]/temp,temp2=n/temp;
                    printf("%d/%d\n",temp1,temp2);
                }
            }
        }
//        for(int i=k; i<=n; i++)
//        {
//            cout<<"0"<<endl;
//        }
    }
    return 0;
}
