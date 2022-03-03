#include <bits/stdc++.h>
using namespace std;

#define LL long long

#define lson l,mid,id<<1
#define rson mid+1,r,id<<1|1
#define ls id<<1
#define rs id<<1|1
#define MID(l,r) (((l)+(r))>>1)

const int MOD = (int) 1e9 + 7;
const double eps = (double) 1e-8;
const int maxn = (int) 2e5 + 20;

LL _sum;
int _mxval, _mxcnt;
map<int, int> hs;

void ans_init()
{
    _sum = 0;
    _mxval = _mxcnt = -1;
    hs.clear();
}

void ans_update(int val, int cnt)
{
    int c = hs[val];
    if(c == 0) _sum += val;
    hs[val] = c + cnt;

    if(c + cnt > _mxcnt || (c + cnt == _mxcnt && val > _mxval))
    {
        _mxval = val;
        _mxcnt = c + cnt;
    }
}

int n, m;
int T[maxn << 2];
int ansval[maxn];
LL anssum[maxn];

void build(int l, int r, int id)
{
    if(l == r)
    {
        scanf("%d", &T[id]);
        return ;
    }
    int mid = MID(l, r);
    build(lson);
    build(rson);

    T[id] = T[ls] == T[rs] ? T[ls] : -1;
}

void ins_bst(int L, int R, int l, int r, int id)
{
    if(T[id] != -1)
    {
        ans_update(T[id], min(r, R) - max(l, L) + 1);
        return ;
    }
    int mid = MID(l, r);
    if(L <= mid) ins_bst(L, R, lson);
    if(mid < R)  ins_bst(L, R, rson);
}

void update(int x, int L, int R, int l, int r, int id)
{
    if(L <= l && r <= R)
    {
        T[id] = x;
        return ;
    }
    if(T[id] != -1)
    {
        T[ls] = T[rs] = T[id];
        T[id] = -1;
    }

    int mid = MID(l, r);
    if(L <= mid) update(x, L, R, lson);
    if(mid < R)  update(x, L, R, rson);

    T[id] = T[ls] == T[rs] ? T[ls] : -1;
}

void work()
{
    scanf("%d%d", &n, &m);
    build(1, n, 1);
    int opt, l, r, x;
    int clk = 0;
    while(m--)
    {
        scanf("%d", &opt);
        if(opt == 1)
        {
            scanf("%d%d%d", &l, &r, &x);
            ans_init();
            ins_bst(l, r, 1, n, 1);
            update(x, l, r, 1, n, 1);


//            cout <<bst.find_max_time().first <<" " <<bst.find_max_time().second <<endl;
            anssum[clk] = _sum;
            ansval[clk] = _mxval;

            clk++;
        }
        else
        {
            scanf("%d", &x);
            if(opt == 2) printf("%lld\n", anssum[clk - x]);
            else printf("%d\n", ansval[clk - x]);
        }
    }
}

int main()
{
#ifdef yukihana0416
freopen("in.txt", "r" ,stdin);
//freopen("out.txt", "w", stdout);
#endif // yukihana0416

    int tc = 1;
//    scanf("%d", &tc);
    for(int ca = 1; ca <= tc; ca++)
    {
//        printf("Case #%d: ", ca);
        work();
    }
    return 0;
}
