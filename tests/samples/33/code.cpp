#include <bits/stdc++.h>
#define ull unsigned long long
const int Mod = 1e9 + 7;

int main() {
	int i, t;
	ull n = 0;
	char s[30], *p;
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		scanf("%s", &s);
		for (p = s, n = 0; *p; p++) n = (n * 10 + (*p - '0')) % Mod;
		n = (n * n % Mod * n % Mod + 5 * n % Mod)  * 166666668  + 1;
		printf("%u\n", n % Mod);
	}
	return 0;
}