#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<pair<int, int> > edge[1005];
int dis[1005],cnt[1005];
bool vis[1005];
int n, m, s;
void spfa() {
	for (int i = 1; i <= n; i++)dis[i] = (1 << 27), cnt[i] = 0;
	dis[s] = 0;
	deque<int> q;
	q.push_back(s);
	vis[s] = 1;
	cnt[s]++;
	while (q.size()) {
		int t = q.front();
		q.pop_front();
		vis[t] = 0;
		for (int k = 0, len = edge[t].size(); k < len; k++) {
			int y = edge[t][k].first;
			int z = edge[t][k].second;
			if (dis[y] > dis[t] + z) {
				dis[y] = dis[t] + z;
				if (!vis[y]) {
					cnt[y] = cnt[t] + 1;
					if (cnt[y] > n) {
						cout << -1;
						exit(0x0);
					}
					if (q.size() && dis[y] < dis[q.front()])
						q.push_front(y);
					else
						q.push_back(y);
					vis[y] = 1;
				}
			}
		}
	}
}
int main() {
	cin >> n >> m >> s;
	while (m--) {
		int x = 0, y = 0, z = 0;
		cin >> x >> y >> z;
		edge[x].push_back(make_pair(y, z));
	}
	bool flag = 0;
	if (!edge[s].size()) {
		flag = 1;
		while (!edge[s].size())s++;
	}
	spfa();
	if(flag)
		for (int i = 1; i <= n; i++)
			if (i==1)printf("0\n");
			else printf("NoPath\n");
	else for (int i = 1; i <= n; i++)
		if (dis[i] != 1 << 27)
			printf("%d\n", dis[i]);
		else printf("NoPath\n");
	return 0;
}