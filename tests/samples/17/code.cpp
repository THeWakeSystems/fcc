#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    if(!n)
    {
        printf("ping\n");
        return 0;
    }
    int i,flag;
    double t=1000000;
    for(i=1;i<=n;i++)
    {
        int  x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        if(z==0)
            continue;
        if(y==0)
        {
            if((double)(x)/z<=t)
            {
                flag=0;
                t=(double)(x)/z;
            }
        }
        else
        {
            if((double)(10000-x)/z<=t)
            {
                flag=1;
                t=(double)(10000-x)/z;
            }
        }
    }
    if(flag)
    {
        printf("right\n");
        printf("%.3f\n",t);
    }
    else
    {
        printf("left\n");
        printf("%.3f\n",t);
    }
    return 0;
}
