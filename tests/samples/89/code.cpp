#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
void input() { freopen("in.txt", "r", stdin), freopen("out.txt", "w", stdout); }

const int N = 510, M = N * 2, inf = 1e8;
int n, w, c[N]; // c数组存小猫的重量
int ans = 0x3f3f3f3f; // 记录最少数量的车数
int a[N]; // 第i辆车已经容纳的小猫重量
void dfs (int x, int cur) {
    if (cur >= ans) return;
    if (x == n + 1) {
        ans = cur;
        return;
    }
    for (int i = 1; i <= cur; i++) {
        if (a[i] + c[x] <= w) {
            a[i] += c[x];
            dfs (x + 1, cur);
            a[i] -= c[x];
        }
    }
    a[cur + 1] = c[x];
    dfs (x + 1, cur + 1);
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   // input(); 
    cin >> n >> w;
    for (int i = 1; i <= n; i++) cin >> c[i];
    //sort(c + 1, c + n + 1);
    sort(c + 1, c + n + 1, greater<int> ());
    dfs (1, 1);
    cout << ans << '\n';
    return 0;
}