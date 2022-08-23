#include<bits/stdc++.h>
using namespace std;
int n, m;
const int N = 1e6 + 5;
struct e {
	int x, y, t;
} op[N], b[N];
int t[N], ans[N];
int optors;
int top;
bool cmp(e a, e b) {
	if (a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}
void add(int p, int num) {
	for (int i = p; i < top; i += i & -i)  t[i] = max(t[i], num);
}
void re(int y) {
	for (; y < top; y += y & -y) t[y] = 0xcfcfcfcf;
}
int ask(int p) {
	int ans = -1e9 + 7;
	for (int i = p; i; i -= i & -i) ans = max(ans, t[i]);
	return ans;
}
void pre() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		top = max(top, y);
		op[i] = {x, y, 1};
	}
	for (int i = 1; i <= m; i++) {
		int x, y, t;
		scanf("%d%d%d", &t, &x, &y);

		top = max(top, y);
		op[i + n] = {x, y, t};
	}
	optors = n + m;
	top++;
}
void work(int be, int end, int d, int dx, int dy) {
	for (int i = be; i != end; i += d) {
		int p = dy == 1 ? b[i].y : top - b[i].y;
		int num = dx * b[i].x + dy * b[i].y;
		if (op[b[i].t].t == 1) add(p, num);
		else ans[b[i].t] = min(ans[b[i].t], abs(num - ask(p)));
	}
	for (int i = be; i != end; i += d)
		if (op[b[i].t].t == 1) re(dy == 1 ? b[i].y : top - b[i].y);
}
void cdq(int l, int r) {
	int mid = (l + r) / 2;
	if (l < mid) cdq(l, mid);
	if (mid + 1 < r) cdq(mid + 1, r);
	int tol = 0;
	for (int i = l; i <= r; i++) {
		if ((op[i].t == 1 && i <= mid) || (op[i].t == 2 && i > mid) ) {
			b[++tol] = op[i];
			b[tol].t = i;
		}
	}
	sort(b + 1, b + 1 + tol, cmp);
	work(1, tol + 1, 1, 1, 1);
	work(1, tol + 1, 1, 1, -1);
	work(tol, 0, -1, -1, -1);
	work(tol, 0, -1, -1, 1);
}

void solve() {
	memset(ans, 0x3f3f3f3f, sizeof(ans));
	memset(t, -0x3f3f3f3f, sizeof t);
	cdq(1, optors);
	for( int i = n; i <= n + m; i++) {
		if (op[i].t == 2) {
			printf("%d\n", ans[i]);
		}
	}
}
int main() {
	pre();
	solve();
	return 0;
}