#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
int n, m, p;
ll ksm(ll x, ll n) {
	ll ret = 1;
	while(n) {
		if(n & 1) ret = (ret * x) % p;
		x = (x * x) % p;
		n >>= 1;
	}
	return ret;
}
ll c(ll a, ll b) {
	ll y = 1, x = 1;
	for(int i = 1; i <= b; i ++) {
		x = (x * (a - i + 1)) % p;
		y = (y * i) % p;
	}
	y = ksm(y, p - 2) % p;
	ll ret = x * y % p;
	return ret;
}
int main() {
	int t;
	scanf("%d", &t);
	while (t -- ) {
		scanf("%d %d %d", &n, &m, &p);
		printf("%d\n", c(n, m) % p);
	}
}