#include<bits/stdc++.h>
using namespace std;

typedef struct
{
    int a,b;
} Node;

bool cmp(Node n1, Node n2)
{
    return n1.a < n2.a;
}

int main()
{
    int L,M,i,res,r,ans;
    Node a[1000002];
    scanf("%d%d",&L,&M);
    for(i =0; i < M; i++){
        scanf("%d%d",&a[i].a,&a[i].b);
    }

    sort(a,a+M,cmp);

    r = -1;
    res = 0;
    for(i = 0; i < M; i++){
        if(a[i].b > r){
            if(a[i].a > r){
                res += a[i].b - a[i].a + 1;
            }
            else{
                res += a[i].b - r;
            }
            r = a[i].b;
        }
    }

    ans = L+1-res;
    printf("%d\n",ans);

    return 0;
}
