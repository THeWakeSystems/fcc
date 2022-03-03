#include<iostream>
#include<cstdio>
using namespace std;
int n,v[39],f[47][47],i,j,k,root[49][49];
void print(int l,int r){
    if(l>r)return;
    if(l==r){printf("%d ",l);return;}
    printf("%d ",root[l][r]);
    print(l,root[l][r]-1);
    print(root[l][r]+1,r);
}
int main() {
    scanf("%d",&n);
    for( i=1; i<=n; i++) scanf("%d",&v[i]);
    for(i=1; i<=n; i++) {f[i][i]=v[i];f[i][i-1]=1;}
    for(i=n; i>=1; i--)
        for(j=i+1; j<=n; j++)
            for(k=i; k<=j; k++) {
                if(f[i][j]<(f[i][k-1]*f[k+1][j]+f[k][k])) {
                    f[i][j]=f[i][k-1]*f[k+1][j]+f[k][k];
                    root[i][j]=k;
                }
            }
    printf("%d\n",f[1][n]);
    print(1,n);
    return 0;
}
