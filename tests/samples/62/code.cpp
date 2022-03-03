/**
 * enjoy coding, good luck, good grades
 */
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> 
void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...); }
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> s(n * 2 + 1);
    for (int i = 1; i <= n * 2; i++) cin >> s[i];
    sort(s.begin() + 1, s.end());
    vector<int> st(510), res(n + 1);
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        st[x] = true;
    }

    function<void(int, int, int, int, int)> find = [&](int l, int r, int pre, int suf, int x) {
        if (l == r) {
            int now = s[n * 2] - pre - suf;
            if (now >= 1 && now <= 500 && st[now]) {
                res[l] = now;
                for (int i = 1; i <= n; i++) {
                    cout << res[i] << ' ';
                }
                cout << '\n';
                exit(0);
            }
            return;
        }
        int a = s[x] - pre;
        if (a >= 1 && a <= 500 && st[a]) {
            res[l] = a;
            find(l + 1, r, s[x], suf, x + 1);
        }
        int b = s[x] - suf;
        if (b >= 1 && b <= 500 && st[b]) {
            res[r] = b;
            find(l, r - 1, pre, s[x], x + 1);
        }
    };

    find(1, n, 0, 0, 1);
    return 0;
}