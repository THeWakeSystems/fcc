/*
PROB: packrec
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct rectangles
{
    int a,b;
    int x,y;
    int x1,x2,y1,y2;
    char used;
}rec[5];
int ts,tmx,tmy;
int S=9999999,nn;
int ans[50];  
int is_insert(int x1,int y1,int x2,int y2)
{
    int i;
    for(i=1;i<=4;i++)
        if(rec[i].used&&rec[i].x1<=x2&&rec[i].x2>=x1&&rec[i].y1<=y2&&rec[i].y2>=y1)
                return 1;
    return 0;
} 
void DFS(int n)
{
    int i,j,k,tx1,tx2,ty1,ty2;
    if(n==1)
    {
        for(i=1;i<=4;i++)
        {
            rec[i].x1=1;
            rec[i].y1=1;
            rec[i].x2=rec[i].a;
            rec[i].y2=rec[i].b;
            rec[i].used=1;
            DFS(n+1);
            rec[i].used=0;
            
            rec[i].x1=1;
            rec[i].y1=1;
            rec[i].x2=rec[i].b;
            rec[i].y2=rec[i].a;
            rec[i].used=1;
            DFS(n+1);
            rec[i].used=0;
        }
        return;
    }
    if(n==5)
    {
      //  for(i=1;i<=4;i++)
         //   cout<<rec[i].x1<<' '<<rec[i].y1<<' '<<rec[i].x2<<' '<<rec[i].y2<<endl;
        tmx=tmy=0;
        for(i=1;i<=4;i++)
        {
            if(rec[i].x2>tmx)
                tmx=rec[i].x2;
            if(rec[i].y2>tmy)
                tmy=rec[i].y2;
        }
        ts=tmx*tmy;
        if(tmx>tmy)
            tmx=tmy;
        if(ts==S)
        {
            for(i=1;i<=nn;i++)
                if(ans[i]==tmx)
                    break;
            if(ans[i]!=tmx)
            {
                nn++;
                ans[nn]=tmx;
            }
        }
        if(ts<S)
        {
            S=ts;
            nn=1;
            ans[1]=tmx;
        }
        return;
    }
    for(i=1;i<=4;i++)
        if(!rec[i].used)
        {
            for(j=1;j<=4;j++)
                if(rec[j].used)
                {
                    for(k=1;k<=4;k++)
                        if(rec[k].used)
                        {
                            tx1=rec[j].x1;                          //1
                            ty1=rec[k].y2+1;
                            tx2=tx1+rec[i].a-1;
                            ty2=ty1+rec[i].b-1;
                            if(!is_insert(tx1,ty1,tx2,ty2))
                            {
                                rec[i].x1=tx1;
                                rec[i].x2=tx2;
                                rec[i].y1=ty1;
                                rec[i].y2=ty2;
                                rec[i].used=1;
                                DFS(n+1);
                                rec[i].used=0;
                            }
                            
                            tx1=rec[j].x2+1;                         //2
                            ty1=rec[k].y1;
                            tx2=tx1+rec[i].a-1;
                            ty2=ty1+rec[i].b-1;
                            if(!is_insert(tx1,ty1,tx2,ty2))
                            {
                                rec[i].x1=tx1;
                                rec[i].x2=tx2;
                                rec[i].y1=ty1;
                                rec[i].y2=ty2;
                                rec[i].used=1;
                                DFS(n+1);
                                rec[i].used=0;
                            }
                            
                            tx1=rec[j].x1;                        //3
                            ty1=rec[k].y2+1;
                            tx2=tx1+rec[i].b-1;
                            ty2=ty1+rec[i].a-1;
                            if(!is_insert(tx1,ty1,tx2,ty2))
                            {
                                rec[i].x1=tx1;
                                rec[i].x2=tx2;
                                rec[i].y1=ty1;
                                rec[i].y2=ty2;
                                rec[i].used=1;
                                DFS(n+1);
                                rec[i].used=0;
                            }
                            
                            tx1=rec[j].x2+1;                       //4
                            ty1=rec[k].y1;
                            tx2=tx1+rec[i].b-1;
                            ty2=ty1+rec[i].a-1;
                            if(!is_insert(tx1,ty1,tx2,ty2))
                            {
                                rec[i].x1=tx1;
                                rec[i].x2=tx2;
                                rec[i].y1=ty1;
                                rec[i].y2=ty2;
                                rec[i].used=1;
                                DFS(n+1);
                                rec[i].used=0;
                            }
                            
                            tx1=rec[j].x2;                          //1
                            ty1=rec[k].y2+1;
                            tx2=tx1+rec[i].a-1;
                            ty2=ty1+rec[i].b-1;
                            if(!is_insert(tx1,ty1,tx2,ty2))
                            {
                                rec[i].x1=tx1;
                                rec[i].x2=tx2;
                                rec[i].y1=ty1;
                                rec[i].y2=ty2;
                                rec[i].used=1;
                                DFS(n+1);
                                rec[i].used=0;
                            }
                            
                            tx1=rec[j].x2+1;                         //2
                            ty1=rec[k].y2;
                            tx2=tx1+rec[i].a-1;
                            ty2=ty1+rec[i].b-1;
                            if(!is_insert(tx1,ty1,tx2,ty2))
                            {
                                rec[i].x1=tx1;
                                rec[i].x2=tx2;
                                rec[i].y1=ty1;
                                rec[i].y2=ty2;
                                rec[i].used=1;
                                DFS(n+1);
                                rec[i].used=0;
                            }
                            
                            tx1=rec[j].x2;                        //3
                            ty1=rec[k].y2+1;
                            tx2=tx1+rec[i].b-1;
                            ty2=ty1+rec[i].a-1;
                            if(!is_insert(tx1,ty1,tx2,ty2))
                            {
                                rec[i].x1=tx1;
                                rec[i].x2=tx2;
                                rec[i].y1=ty1;
                                rec[i].y2=ty2;
                                rec[i].used=1;
                                DFS(n+1);
                                rec[i].used=0;
                            }
                            
                            tx1=rec[j].x2+1;                       //4
                            ty1=rec[k].y2;
                            tx2=tx1+rec[i].b-1;
                            ty2=ty1+rec[i].a-1;
                            if(!is_insert(tx1,ty1,tx2,ty2))
                            {
                                rec[i].x1=tx1;
                                rec[i].x2=tx2;
                                rec[i].y1=ty1;
                                rec[i].y2=ty2;
                                rec[i].used=1;
                                DFS(n+1);
                                rec[i].used=0;
                            }
                        }
                }
        }
}
int main()
{
    int i;
    memset(rec,0,sizeof(rec));
    for(i=1;i<=4;i++)
        cin>>rec[i].a>>rec[i].b;
    DFS(1);
    cout<<S<<endl;
    sort(ans+1,ans+1+nn);
    for(i=1;i<=nn;i++)
        cout<<ans[i]<<' '<<S/ans[i]<<endl;
    return 0;
}    
