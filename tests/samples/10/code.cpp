/*by SilverN*/
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
int main(){
    int i,j,n,m;
    scanf("%d",&n);
    m=n+1;
    int ans=0;
    while(m>1){
        if(m&1)ans++;
        m>>=1;
    }
    printf("%d\n",ans);//mini
    m=n+1;
    ans=0;
    while(m>1){
        if(m==2)ans++;
        if(m&3){
            if((m&3)==1){
                ans+=m/4*2-1;
                m/=4;m++;
            }
            else if((m&3)==2){
                ans+=m/4*2;
                m/=4;m++;
            }
            else if((m&3)==3){
                ans+=m/4*2+1;
                m/=4;m++;
            }
        }
        else{
            ans+=m/4*2;
            m/=4;
        }
    }
    printf("%d\n",ans);//max
    return 0;
}