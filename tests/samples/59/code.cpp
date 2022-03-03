#include <iostream>
#include<algorithm>
using namespace std;
struct node{
    double x;
    int y;
    double sum;
    int id;
}a[2005];
int cmp(node x1,node x2)
{
    return x1.sum>x2.sum;
}
int main()
{
    int b[2005];
    int n,m,k;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a[i].x;
        b[i]=0;
    }
     for(int i=0;i<m;i++){
        cin>>a[i].y;
        a[i].id=i;
     }
    for(int i=0;i<m;i++){
        a[i].sum=a[i].x*a[i].y;
    }
    sort(a,a+m,cmp);
    k=n/3;
    for(int i=0;i<k;i++){
        b[a[i].id]=1;
    }
    for(int i=0;i<m;i++){
        cout<<b[i];
    }
    return 0;
}
