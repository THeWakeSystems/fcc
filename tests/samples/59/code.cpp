#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<math.h>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<string.h>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<iomanip>
#ifdef _MSC_VER
#  include <intrin.h>
#  define __builtin_popcount __popcnt
#endif
#define N 110
#define M 1000010
#define INF 0x3f3f3f3f
#define ll long long
#define mod 1000000007
using namespace std;
ll n,a,cnt, p[N];
bool ins(ll x) {
	for (ll i = 62; i >= 0; --i)
		if (x & (1ll << i)) {
			if (!p[i]) {
				p[i] = x;
				cnt++;
				return 1;
			}
			else
				x ^= p[i];
		}
	return 0;
}
int main() {
	scanf("%lld", &n);
	for (ll i = 1; i <= n; ++i) {
		scanf("%lld", &a);
		ins(a);
	}
	if (cnt & 1)
		printf("First\n");
	else
		printf("Second\n");
	return 0;
}