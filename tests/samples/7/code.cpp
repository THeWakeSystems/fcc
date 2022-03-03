#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int vis[N],prime[N],top;
vector<int>ans;
vector<int>two;
void getPrime(){
	memset(vis,0,sizeof vis);
	for(int i=2;i<N;i++){
		if(!vis[i]){
			prime[top++]=i;
			for(int j=2;i*j<N;j++){
				vis[i*j]=1;
			}
		}
	} 
}
void init(){
	while(!ans.empty()){
		ans.pop_back();
	}
}
int main(){
	getPrime();
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		init();
		int id=upper_bound(prime,prime+top,n/2)-prime;
		memset(vis,0,sizeof vis);
		for(int i=id-1;i>=0;i--){
			int p=prime[i],num=0;
			for(int j=1;p*j<=n;j++){
				if(j==2)
					continue;
				if(!vis[p*j]){
					num++;
					ans.push_back(p*j);
					vis[p*j]=1;
				}
			}
			if(num%2){
				vis[2*p]=1;
				ans.push_back(2*p);
			}
			
			
		}
		int res=ans.size()/2;
		cout<<res;
		for(int i=0;i<ans.size();i++){
			cout<<" "<<ans[i];
		}
		cout<<endl;
		
	}
	return 0;
}