#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int n,m1,m2,ans=150000; 
int i,j;
int s[10001],f[10001];
bool p[30001];
int prime[501][3],size=0;
int main()
{
//	freopen("in.txt","r",stdin);
  //      freopen("out.txt","w",stdout);
    memset(p,1,sizeof(p));
    memset(f,0,sizeof(f));
    scanf("%d%d%d",&n,&m1,&m2);
    if (m1 == 1) { printf("0"); return 0; }  //1.若试管数为1，直接符合条件 
    for (i=1; i<=n; i++)
      scanf("%d",&s[i]);
    int xx=floor(sqrt(m1));
    for (i=2; i<=xx; i++) //找质因数 
      if (p[i])
      {
            if (m1 % i == 0)
            {
                prime[++size][1]=i;
                prime[size][2]=1;
          }
            int tim=2;
            while (tim*i <= m1)
            {
                  p[tim*i]=0;
                  tim++;
            }
      }
    for (i=1; i<=size; i++) //找质因数个数 
    {
        int num=prime[i][1];
        while (m1 % (num*prime[i][1]) == 0)
        {
            num*=prime[i][1];
            prime[i][2]++;
        }
        prime[i][2] *= m2;
    }
    if (size == 0) //若为质数，质因数为本身 
    {
        prime[++size][1] = m1;
        prime[size][2] = m2;
    }
    for (i=1; i<=n; i++)
    {
        for (j=1; j<=size; j++)
        {
            if (s[i] % prime[j][1] != 0) //若无某个因数，直接break 
            {
                f[i] = 150000; //极大值 : 10000*log 2 30000 
                break;
            }
            int tim=1;
            long long num=prime[j][1];
            while (s[i] % (num*prime[j][1]) == 0)
            {
                num*=prime[j][1];
                tim++;
            }
            int an=(prime[j][2]-1) / tim + 1; //等价于ceil函数 
            if (an > f[i]) f[i] = an;
        }
    }   
    for (i=1; i<=n; i++)
      if (ans > f[i]) ans=f[i];
    if (ans == 150000) printf("-1"); 
    else printf("%d",ans);

//   fclose(stdin);
 //  fclose(stdout);
    return 0;
}
