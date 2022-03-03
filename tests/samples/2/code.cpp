#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int exgcd(int a,int b,int &x,int &y){//扩展欧几里得
    if(b==0){
        y=0;
        x=1;
        return a;
    }
    int q=exgcd(b,a%b,x,y);
    int temp=x;
    x=y;
    y=temp-a/b*y;
    return q;
} 
int main(){
    int i,j,k,m,n,a,b;
    scanf("%d%d",&m,&n);
    int gcd=exgcd(m,n,a,b);//再求最小整数解
    printf("%d\n",(a%n+n)%n);//这里是为了消除负数的情况，原是(a%(n/gcd(a,b))+(n/gcd(a,b))%(n/gcd(a,b)；但由于gcd(a,b)==1所以这么写
    return 0;
}
