#include <bits/stdc++.h>
#define fo(i, a, b) for (int i = (a); i <= (b); i ++)
using namespace std;

const int N = 1e2 + 3;
const int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int n, x, k, tot;
int a[N], b[N][N];

int X[N * N], Y[N * N];
int f[N][N];

int main() {
	scanf("%d%d%d", &n, &x, &k);
	
	fo(i, 1, n)
		a[i] = n + i - 1;
	fo(i, n + 1, n + n - 1)
		a[i] = n + 2 * n - i - 1;
		
	n = n * 2 - 1;
	int sx, sy;
	fo(i, 1, n)
		fo(j, 1, a[i]) {
			b[i][j] = ++ tot;
			if (tot == x) sx = i, sy = j; 
		}
		
	X[1] = sx, Y[1] = sy;
	memset(f, -1, sizeof f);
	f[sx][sy] = 0;
	int h = 1, t = 1;
	for (; h <= t; ++ h) {
		int nx, ny;
		fo(i, 0, 3) {
			nx = X[h] + dir[i][0], ny = Y[h] + dir[i][1];
			if (nx < 1 || ny < 1 || nx > n || ny > a[nx]) continue;
			if (f[nx][ny] > - 1) continue;
			
			f[nx][ny] = f[X[h]][Y[h]] + 1;
			++ t, X[t] = nx, Y[t] = ny;
		}
		
		int tp;
		// go up
		if (X[h] <= (n + 1) >> 1) tp = - 1;
		else tp = 1;
		
		nx = X[h] - 1, ny = Y[h] + tp;
		if (nx < 1 || ny < 1 || nx > n || ny > a[nx]) goto NEX;
		if (f[nx][ny] > - 1) goto NEX;
		
		f[nx][ny] = f[X[h]][Y[h]] + 1;
		++ t, X[t] = nx, Y[t] = ny;
	
		NEX:;
	
		// go down
		if (X[h] <= n >> 1) tp = 1;
		else tp = - 1;
		
		nx = X[h] + 1, ny = Y[h] + tp;
		if (nx < 1 || ny < 1 || nx > n || ny > a[nx]) goto NEX1;
		if (f[nx][ny] > - 1) goto NEX1;
		
		f[nx][ny] = f[X[h]][Y[h]] + 1;
		++ t, X[t] = nx, Y[t] = ny;
		
		NEX1:;
	}
		
	int cnt = 0;
	fo(i, 1, n)
		fo(j, 1, a[i])
			if (f[i][j] == k) ++ cnt;
	printf("%d\n", cnt);
	
	fo(i, 1, n)
		fo(j, 1, a[i])
			if (f[i][j] == k)
				printf("%d\n", b[i][j]);
}
