#include<bits/stdc++.h>
using namespace std;
const int nn=2030;
bool s[nn];
int n,m,k,ans;
int sg[nn];
vector<int>v[nn];
void dfs(int ui){
	if (sg[ui]==-1){
		for (auto it:v[ui]) dfs(it);
		memset(s,0,sizeof(s));
		for (auto it:v[ui]) s[sg[it]] = 1;
		for (int i=0;;i++){
			if (!s[i]){
				sg[ui] = i;
				break;
			}
		}
	}
}
int main(){
	memset(sg,-1,sizeof(sg));
	scanf("%d %d %d",&n,&m,&k);
	for (int i=0;i<m;i++){
		int ui,vi;scanf("%d %d",&ui,&vi);
		v[ui].push_back(vi);
	}
	for (int i=0;i<k;i++){
		int x;scanf("%d",&x);
		dfs(x);ans ^= sg[x];
	}
	puts(ans?"win":"lose");
}