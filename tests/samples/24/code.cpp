#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int n,p,ans=0,i,j,t=0,x=1,y=0,a[1000][1000]={0};
    cin>>n;
    cin>>p;
    while(t<n*n){
        while(y<n&&a[x][y+1]==0){
            t++;
            ans+=t;
            a[x][++y]=ans;
        }
         while(x<n&&a[x+1][y]==0){
            t++;
            ans+=t;
            a[++x][y]=ans;
        }
        while(y>1&&a[x][y-1]==0){
            t++;
            ans+=t;
            a[x][--y]=ans;
        }
        while(x>1&&a[x-1][y]==0){
            t++;
            ans+=t;
            a[--x][y]=ans;
        }
    }
    if(p%4==2||p%4==0){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    if(p%4==1)
    {
        for(i=1;i<=n;i++){
            for(j=n;j>=1;j--){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    if(p%4==3)
    {
        for(i=n;i>=1;i--){
            for(j=1;j<=n;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}