#include<bits/stdc++.h>

using namespace std;

int a[35][35];
int n;

int guass(){
	int c,r;
	for(c=0,r=0;c<n;c++){
		int t=r;
		for(int i=r;i<n;i++){
			if(a[i][c]){
				t=i;
				break;
			}
		}
		if(!a[t][c])continue;
		for(int i=c;i<=n;i++) swap(a[r][i],a[t][i]);
		
		for(int i=r+1;i<n;i++){
//			printf("i=%d c=%d %d\n",i,c,a[i][c]);
			if(a[i][c]){
				for(int j=c;j<=n;j++){
					a[i][j]^=a[r][j];
				}
			}
		}
		r++;
	}
	if(r<n){
		int num=0;
		for(int i=r;i<n;i++){
			if(a[i][n])return 0;
			num++;
		}
		return 1<<num;
	}
	
//	for(int i=n-1;i>=0;i--){
//		for(int j=i+1;j<n;j++){
//			a[i][n] ^= a[i][j] & a[j][n];
//		}
//	}
	return 1;
}

int main(){
	int T;
	cin>>T;
	while(T--){
		memset(a,0,sizeof(a));
		cin>>n;
		int x;
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			a[i][n]=x;
		}
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			a[i][n]^=x;
		}
		int y;
		for(int i=0;i<n;i++){
			a[i][i]=1;
		}
		while(scanf("%d%d",&x,&y)){
			if(x==0&&y==0)break;
			a[y-1][x-1]^=1;
		}
		
		int ans=guass();
		
		if(!ans){
			cout<<"Oh,it's impossible~!!"<<endl;
		}else{
			cout<<ans<<endl;
		}
	}
	
	
	return 0;
}