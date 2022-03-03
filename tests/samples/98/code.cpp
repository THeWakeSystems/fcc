#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define mem(a, b) memset(a, b, sizeof a) // others
#define endl '\n'

typedef unsigned long long ull;
typedef pair<int, int> pii;

template<class T> void minn(T& a, T b) {if (a > b) a = b;}
template<class T> void maxx(T& a, T b) {if (a < b) a = b;}

const int mod = 1e9 + 7;
const int N = 2e5 + 5;
int n;
int rt, tot;
#define ls (t[i].l)
#define rs (t[i].r)
struct e{
    int l, r;
    int v, cnt;
    int sz, rnd;
}t[N * 10];
void pushup(int i) {
    t[i].sz = t[ls].sz + t[rs].sz + t[i].cnt;
}
void rturn(int &i) {
    int l = t[i].l;
    t[i].l = t[l].r;
    t[l].r = i;
    t[l].sz = t[i].sz;
    pushup(i);
    i = l;
}
void lturn(int &i) {
    int r = t[i].r;
    t[i].r = t[r].l;
    t[r].l = i;
    t[r].sz = t[i].sz;
    pushup(i);
    i = r;
}
void ins(int &i, int v) {
    if (!i) {
        i = ++tot;
        t[i] = {0, 0, v, 1, 1, rand() % 19620817};
        return;
    }
    if (v == t[i].v) {
        t[i].cnt++;
        t[i].sz++;
        return;
    }
    t[i].sz++;
    if (v < t[i].v) {
        ins(ls, v);
        if (t[ls].rnd < t[rs].rnd) rturn(i);
    }
    else {
        ins(rs, v);
        if (t[ls].rnd > t[rs].rnd) lturn(i);
    }
}
void del(int& i, int v) {
    if (t[i].v == v) {
        if (t[i].cnt > 1) {t[i].cnt--; t[i].sz--;return;}
        if (!ls || !rs) i = ls + rs;
        else if (t[ls].rnd < t[rs].rnd) {rturn(i); del(i, v);}
        else {lturn(i); del(i, v);}
    }
    else if (v < t[i].v) del(ls, v);
    else del(rs, v);
    pushup(i);

}
int find(int i, int v) {
    if (!i) return 0;
    if (v == t[i].v) return t[ls].sz + 1;
    if (v <= t[i].v) return find(ls, v);
    else return t[ls].sz + t[i].cnt + find(rs, v);
}
int Rank(int i, int k) {
    if (t[ls].sz < k) {
        if (t[ls].sz + t[i].cnt >= k) return t[i].v;
        return Rank(rs, k - t[i].cnt - t[ls].sz);
    }
    else return Rank(ls, k);
}
int pre(int v) {
    int i = rt;
    int res = -1e9 + 7;
    while (i) {
        if (v == t[i].v) {
            if (ls) {
                i = ls;
                while (rs) i = rs;
                res = t[i].v;
            }
            break;
        }
        if (t[i].v < v) maxx(res, t[i].v);
        v < t[i].v ? i = ls : i = rs;
    }
    return res;
}
int nxt(int v) {
    int i = rt;\

    int res = 1e9 + 7;
    while (i) {
        if (v == t[i].v) {
            if (rs) {
                i = rs;
                while (ls) i = ls;
                res = t[i].v;
            }
            break;
        }
        if (t[i].v > v) minn(res, t[i].v);
        v < t[i].v ? i = ls : i = rs;
    }
    return res;
}
void solve() {
    scanf("%d", &n);
    while (n--) {
        int op, x;
        scanf("%d%d", &op, &x);
        if (op == 1) {
            ins(rt, x);
        }
        if (op == 2) {
            del(rt, x);
        }
        if (op == 3) {
            printf("%d\n", find(rt, x));
        }
        if (op== 4) {
            printf("%d\n", Rank(rt, x));
        }
        if (op == 5) {
            printf("%d\n", pre(x));
        }
        if (op == 6) {
            printf("%d\n", nxt(x));
        }
    }
}
signed main()
{
    int T = 1;
    srand(19620817);
    while (T--) {
        solve();
    }
}


