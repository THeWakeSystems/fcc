//#pragma GCC optimize(3)
#include <bits/stdc++.h>
const int I=1000005;
int a[I],c[I],l[I],r[I],n,m,x=-1;
long long cf[I];
long long sum;
bool flag=1;
using namespace std;
int main(){

	ios::sync_with_stdio(false);//输入优化 
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++){//差分数组 
		cin>>c[i]>>l[i]>>r[i];
		cf[l[i]]+=c[i];
		cf[r[i]+1]-=c[i];
	}
	int j=m;//PAT：从后往前推，只要发现删除哪个后正好符合要求，则其为ans 
	for(int i=1;i<=n;i++){
		sum+=cf[i];//计算每个教室的使用情况 
		if(sum>a[i]){// 
			while(sum>a[i]){//从后往前撤回消息 
				cf[l[j]]-=c[j];
				cf[r[j]+1]+=c[j];
				if(l[j]<=i&&i<=r[j])//PAT：如果一个请求包含了第i个教室，则删除它会影响sum的值 
					sum-=c[j];
				j--;
			}
			if(flag)x=j,flag=0;//更新x 
			else
				x=min(x,j);
		}
	}
	if(x==-1)cout<<"0";
	else cout<<"-1"<<endl<<x+1;
	return 0;
}
