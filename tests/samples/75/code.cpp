#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e5+5;
int n,a[N],b[N],cnt[N],len,tp;
void mul(int x){
	for(int i=1;i<=len;i++)b[i]=a[i];
	int jz=0,tp=0;
	for(int i=len,tmp;i;i--)
		tmp=b[i]*x+jz,a[++tp]=tmp%10,jz=tmp/10;
	if(jz){while(jz)a[++tp]=jz%10,jz/=10;}
	reverse(a+1,a+tp+1);len=tp;
}
void divide(int x,int y){
	for(int i=2;i*i<=x;i++)if(x%i==0)
		while(x%i==0)x/=i,cnt[i]+=y;
	if(x>1)cnt[x]+=y;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)divide(i,-2);
	divide(n+1,-1);
	for(int i=1;i<=(n<<1);i++)divide(i,1);
	a[len=1]=1;
	for(int i=1;i<=(n<<1);i++)for(int j=1;j<=cnt[i];j++)mul(i);
	for(int i=1;i<=len;i++)printf("%d",a[i]);puts("");
	return 0;
}
