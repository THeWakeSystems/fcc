#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;

bool isPrime[MAXN];
int Prime[MAXN];
int cnt;
void Euler() {
  isPrime[1] = 0;
  memset(isPrime, 1, sizeof isPrime);
  for (int i = 2; i < MAXN; ++i) {
    if (!isPrime[i]) {
      Prime[cnt++] = i;
    }
    for (int j = 0; j < cnt; ++j) {
      if (1ll * i * Prime[j] >= MAXN)break;
      isPrime[i * Prime[j]] = 0;
      if (!(i % Prime[j]))
        break;
    }
  }
}
int a[MAXN];
signed main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  sort(a, a + n);
  long long sum = 0;
  for (int i = 0; i < k; i++) {
    sum += a[n - i - 1];
  }
  printf("%lld", sum);
  return 0;
}
