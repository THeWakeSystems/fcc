#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int fir[28], nxt[100002], to[100002], tot;
inline void add(int a, int b) {
    nxt[++tot] = fir[a];
    fir[a] = tot;
    to[tot] = b;
}
int in[28], out[28], bein[28], beout[28], visit[100002], sum, pre[28];
void DFS(int x) {
    for (int i = fir[x]; i; i = nxt[i]) {
        if (!visit[i]) {
            visit[i] = 1;
            ++sum;
            DFS(to[i]);
        }
    }
}
int get(int x) {
    return pre[x] == x ? x : pre[x] = get(pre[x]);
}
int main() {
    int t, n;
    string s;
    scanf("%d", &t);
    while (t--) {
        memset(fir, 0, sizeof fir);
        memset(nxt, 0, sizeof nxt);
        memset(in, 0, sizeof in);
        memset(out, 0, sizeof out);
        memset(visit, 0, sizeof visit);
        for (int i = 1; i <= 26; ++i) {
            pre[i] = i;
        }
        scanf("%d", &n);
        tot = 0, sum = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> s;
            int a = *s.begin() - 'a' + 1, b = *(s.end() - 1) - 'a' + 1;
            add(a, b);
            ++out[a], ++in[b];
            int k1 = get(a), k2 = get(b);
            pre[k1] = k2;
        }
        int totin = 0, totout = 0, pr = 0;
        for (int i = 1; i <= 26; ++i) {
            if (!pr && fir[i]) {
                pr = get(i);
            } else if(fir[i]) {
                if (pr != get(i)) {
                    puts("The door cannot be opened.");
                    goto con;
                }
            }
            if (out[i] != in[i]) {
                if (out[i] == in[i] + 1) {
                    beout[totout++] = i;
                } else if (in[i] == out[i] + 1) {
                    bein[totin++] = i;
                } else {
                    puts("The door cannot be opened.");
                    goto con;
                }
            }
        }
        if (totin > 1 || totout > 1) {
            puts("The door cannot be opened.");
            continue;
        } /*else if (totout == 1) {
            DFS(*beout);
        } else {
            for (int i = 1; i <= 26; ++i) {
                if (fir[i]) {
                    DFS(i);
                }
            }
        }
        if (sum == n) {
            puts("Ordering is possible.");
        } else {
            puts("The door cannot be opened.");
        }*/
        puts("Ordering is possible.");
        con: continue;
    }
    return 0;
}