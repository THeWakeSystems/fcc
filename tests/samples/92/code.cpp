#include<bits/stdc++.h>

using namespace std;

int n,m,a[30],dep;

int f(){
	int res=0;
	for(int i=2;i<=n;i++){
		if(a[i]!=a[i-1]+1)res++;
	}
	return (res+2)/3;
}

bool check(){
	for(int i=1;i<=n;i++){
		if(a[i]!=i)return false;
	}
	return true;
}

void pt(){
	for(int i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
	printf("\n\n");
}
bool dfs(int step){
	if(step+f()>dep)return false;
	if(check())return true;
	int b[30];
//	pt();
	for(int i=1;i<=n;i++)b[i]=a[i];
	for(int len=1;len<=n;len++){
		for(int l=1;l+len-1<=n;l++){
			int r=l+len-1;
			
			for(int t=r+1;t<=n;t++){
				int p=1;
				for(int k=1;k<l;k++){
					a[p++]=b[k];
				}
				for(int k=r+1;k<=t;k++){
					a[p++]=b[k];
				}
				for(int k=l;k<=r;k++){
					a[p++]=b[k];
				}
				for(int k=t+1;k<=n;k++){
					a[p++]=b[k];
				}
				if(p==n+1&&dfs(step+1)) return true;
			}
			for(int i=1;i<=n;i++)a[i]=b[i];
		}
	}
	return false;
}

int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		int ju=5;
		for(int i=0;i<=4;i++){
			dep=i;
			if(dfs(0)){
				ju=i;
				break;
			}
		}
		if(ju<5){
			printf("%d\n",ju);
		}else{
			printf("5 or more\n");
		}
	}
	
	
	return 0;
}