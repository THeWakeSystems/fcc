/*
PROB: dualpal
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N,S,i,j,k,s,t;
    char ch[128];
    cin>>N>>S;
    while(N--)
    {
        while(1)
        {
            S++;
            s=0;
            for(i=2;i<=10;i++)
            {
                t=S;
                k=0;
                while(t)
                {
                    ch[k]=t%i;
                    t/=i;
                    k++;
                }
                for(j=k/2;j>=0;j--)
                    if(ch[k-j-1]!=ch[j])
                        break;
                if(j==-1)
                {
                    s++;
                    if(s==2)
                        break;
                }    
            }
            if(s==2)
            {
                cout<<S<<endl;
                break;
            }
        }
    }
    return 0;
}
        
