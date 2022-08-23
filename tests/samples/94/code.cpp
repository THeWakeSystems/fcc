#include<bits/stdc++.h>
using namespace std;
struct mat
{
	int a[35][35];
};

int n,k,m;
mat x,ans;
mat operator * (const mat &x,const mat &y)
{
	mat t;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			t.a[i][j]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++){
				t.a[i][j]+=x.a[i][k]*y.a[k][j];
				t.a[i][j]%=m;
			}
	return t;
}
mat operator + ( mat x,mat y)
{
	mat t;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) 
		t.a[i][j]=(x.a[i][j]+y.a[i][j])%m;
	return t;
}
mat operator ^ (mat x,int k)
{
	mat t;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(i==j) t.a[i][j]=1;
			else t.a[i][j]=0;
		}
	while(k){
		if(k&1) t=t*x;
		x=x*x;
		k>>=1;
	}
	return t;
}
mat s(int k)
{
	if(k==1) return x;
	else{
		mat t=s(k>>1);
		if(k&1){
			mat t1=x^((k>>1)+1);
			return t+t1+t*t1;
		}
		else{
			mat t1=x^(k>>1);
			return t+t*t1;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>k>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) cin>>x.a[i][j],x.a[i][j]%=m;
	ans=s(k);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
		cout<<ans.a[i][j]<<" ";
		cout<<'\n';
	}
}