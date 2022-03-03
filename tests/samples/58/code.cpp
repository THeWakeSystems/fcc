#include<bits/stdc++.h>
using namespace std;
int n,m;
string str[1005];
map<string,int> ma;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>str[i]>>x;
		ma[str[i]]=x;
	}
	for(int j=1;j<=m;j++){
		int k;
		scanf("%d",&k);
		for(int i=1;i<=k;i++){
			string a;
			int x;
			cin>>a>>x;
			ma[a]-=x;
			if(ma[a]<0){
				cout<<"NO"<<endl;
				return 0;
			}
		}
	}
	cout<<"YES"<<endl;
	for(int i=1;i<=n;i++)
		if(ma[str[i]])	cout<<str[i]<<" "<<ma[str[i]]<<endl;
	return 0;
}