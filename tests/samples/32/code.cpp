#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e2 + 7;
char s[MAXN][MAXN];
void solve() {
    int h, w, n;
    scanf("%d%d%d", &h, &w, &n);
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if ((i + j) & 1) s[i][j] = '*';
            else if (n) s[i][j] = '#', n--;
            else s[i][j] = '*';
        }
    }
    if (n) printf("-1\n");
    else {
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                printf("%c", s[i][j]);
            }
            printf("\n");
        }
    }
}
int main() {
    solve();
    return 0;
}