/*
LANG: C++
PROB: ttwo
*/
#include<bits/stdc++.h>
int main()
{
//    int d[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
    int d[4][2]={{0,-1},{1,0},{0,1},{-1,0}};
    char map[12][12];
    int fx,fy,tfx,tfy,df,cx,cy,tcx,tcy,dc;
    int i,j;
    for(i=0;i<10;i++)
        scanf("%s",map[i]);
    for(i=0;i<10;i++)
        for(j=0;j<10;j++)
        {
            if(map[i][j]=='F')
                fx=j,fy=i,map[i][j]='.';
            if(map[i][j]=='C')
                cx=j,cy=i,map[i][j]='.';
        }
    df=dc=0;
    for(i=0;i<160000;i++)
    {
        if(fx==cx&&fy==cy)
            break;
        tfx=fx+d[df][0];
        tfy=fy+d[df][1];
        if(tfx>=0&&tfx<10&&tfy>=0&&tfy<10&&map[tfy][tfx]=='.')
            fx=tfx,fy=tfy;
        else
            df++,df%=4;
        tcx=cx+d[dc][0];
        tcy=cy+d[dc][1];
        if(tcx>=0&&tcx<10&&tcy>=0&&tcy<10&&map[tcy][tcx]=='.')
            cx=tcx,cy=tcy;
        else
            dc++,dc%=4;
    }
    if(i>=160000)
        printf("0\n");
    else
        printf("%d\n",i);
    return 0;
}
        

