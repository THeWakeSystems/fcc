#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
map<string,int> dat;
const int MAXN = 350;
int a[MAXN][MAXN];
int b[MAXN],ans[MAXN];
int n,m,x,num;
string s,e;
void init(){
	dat["MON"] = 1; dat["TUE"] = 2;
	dat["WED"] = 3; dat["THU"] = 4;
	dat["FRI"] = 5; dat["SAT"] = 6;
	dat["SUM"] = 7;
}
void solve(){
	int i = 1,j = 1,l,x,y;
	while(i <= m && j <= n){
		for(l = i;l <= m;l++){
			if(a[l][j])	break;
		}
		if(l > m){		//attention!
			j++; 
			continue;
		}
		for(int k = n;k;k--) swap(a[l][k],a[i][k]);
		swap(b[l],b[i]);
		x = a[i][j];
		for(l = i+1;l <= m;l++){
			y = a[l][j];
			for(int k = j;k <= n;k++){
				a[l][k] = (a[l][k]*x - a[i][k]*y)%7;//attention!
			}
			b[l] = (b[l]*x - b[i]*y)%7;//too!
		}
		i++,j++;
	}
	for(l = i;l <= m;l++)				//attention!
		if(b[l]){ puts("Inconsistent data."); return; }
	if(i != j || j < n){ puts("Multiple solutions."); return;}
	//分别对应变量系数为0、方程数不够未知数个数
	int k;
	//for(i = 1;i <= n;i++)	cout << b[i] << " " << a[i][i] << endl;
	for(i--,j--;i;i--,j--)
	{
		for(l=0,k=j+1;k<=n;k++) l+=a[i][k]*ans[k];
		for(k=3;k<=9;k++)
			if((a[i][j]*k%7+7)%7==((b[i]-l)%7+7)%7) ans[i]=k;
	}
	for(i = 1;i < n;i ++) printf("%d ",ans[i]);
	cout << ans[i] << endl;
} 
int main(){
	init();
	while(scanf("%d%d",&n,&m) && n && m){
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		memset(ans,0,sizeof ans);
		for(int i = 1;i <= m;i++){
			scanf("%d",&num);
			cin >> s >> e;
			b[i] = (dat[e] - dat[s] + 8) % 7;
			while(num--){
				scanf("%d",&x);
				a[i][x]++;
			}
			for(int j = 1;j <= n;j++)	a[i][j] %= 7;
		}
		solve();
	}
}