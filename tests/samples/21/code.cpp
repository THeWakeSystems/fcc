#include<bits/stdc++.h>
using namespace std;
#define int long long

#ifdef _KHORAY
#define out(args...) {cout<<"["<<#args<<"]=["; debug(args); cout<<"]\n";}
#else
#define out(args...) 42
#endif

template<typename T>
void debug(T a) {
    cout << a;
}

template<typename T, typename ...args>
void debug(T a, args...b) {
    cout << a << ",";
    debug(b...);
}

template<typename T>
ostream& operator << (ostream &os, vector<T> &v) {
	cout << "[";
	for(T &x : v) {
		cout << x;
		if(&x != &v.back()) {
			cout << ",";
		}
	}
	cout << "]";
}

void solve(int testcase) {
	int n, m, p;
    cin >> n >> m >> p;
    vector<vector<int>> f(5001, vector<int>(5001));
    f[0][0] = 1;
    for(int i = 1; i < 5001; i++) {
        for(int j = 1; j <= i; j++) {
            f[i][j] = (f[i - 1][j - 1] + f[i - 1][j] * (j - 1) % p) % p;
        }
    }
   
    vector<int> L(n + 1), down(m + 1), fac(m + 1);
    down[0] = 1;
    fac[0] = 1;
    for(int i = 1; i <= m; i++) {
        down[i] = down[i - 1] * (m - i + 1) % p;
        fac[i] = fac[i - 1] * i % p;
    }
    out(f[3][2]);
    for(int i = 1; i <= n; i++) {
        cin >> L[i];
    }
    vector<int> dp(1);
    dp[0] = 1;
    for(int i = 1; i <= n; i++) {
        vector<int> ndp(L[i] + 1);
        int sum = 0;
        for(int &x : dp) sum = (sum + x) % p;
        for(int j = 1; j <= min(m, L[i]); j++) {
            if(j > L[i - 1]) {
                ndp[j] = sum * down[j] % p * f[L[i]][j] % p;
            } else {
                ndp[j] = (sum * down[j] % p * f[L[i]][j] % p - dp[j] * fac[j] % p * f[L[i]][j] % p + p) % p; //todo f
            }
        }
        dp = ndp;
        out(sum, i, ndp);
    }
    int ans = 0;
    for(int &x : dp) ans = (ans + x) % p;
    cout << ans;

}

signed main() {
    int t = 1;
    for(int i = 1; i <= t; i++) {
        solve(i);
    }
    return 0;
}

