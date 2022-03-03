#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
const int N = 1e5;
int r[N + 5], c[N + 5], s[N + 5];
int x, y, i, n, m, avg, ans;
long long t, res1, res2;

bool ch(int x)
{
	return (t % x == 0) ? 1 : 0;
}

int calcu(int a[], int x)
{
	ans = 0;
	memset(s, 0, sizeof(s));
	avg = t / x;
	for(int i = 1; i <= x; ++i)
	{
		a[i] = a[i] - avg;		//printf("a[%d] = %d ", i, a[i]);
		s[i] = s[i - 1] + a[i]; //printf("s[%d] = %d\n", i, s[i]);
	}
	sort(s + 1, s + x + 1);
	int mid = x / 2;
	if(x / 2)	++mid;
	for(int i = 1; i <= x; ++i)
	{
		ans += abs(s[i] - s[mid]);
		//printf("s[%d] - %d = %d\n", i, s[x / 2], ans);
	}
	return ans;
}

int main()
{
	scanf("%d%d%lld", &n, &m, &t);
	if(t == 0)
	{
		printf("impossible\n");
		return 0;
	}
	for(int i = 1; i <= t; ++i)
	{
		scanf("%d%d", &y, &x);
		++r[y];	++c[x];
	}
	if(ch(n))
	{
		res1 = calcu(r, n);
	}
	if(ch(m))
	{
		res2 = calcu(c, m);
	}
	if(ch(n) && ch(m))
		printf("both %lld\n", res1 + res2);
	else if(ch(n))
		printf("row %lld\n", res1);
	else if(ch(m))
		printf("column %lld\n", res2);
	else 
		printf("impossible\n");
	return 0;
}
