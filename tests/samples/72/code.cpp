#include <iostream>
#include <cstring>

using namespace std;

const int N = 25;

int n, m, mod;
char str[N];
int ne[N], a[N][N];

void mul(int c[][N], int a[][N], int b[][N])
{
    static int t[N][N];
    memset(t, 0, sizeof t);//如果写了static，就不能通过static int t[N][N] = 0的方式初始化，因为只会调用一次 

    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            for (int k = 0; k < m; k++)
                t[i][j] = (t[i][j] + a[i][k] * b[k][j]) % mod;

    memcpy(c, t, sizeof t);
}

int qmi(int k)
{
    int f[N][N] = { 1 };//为了简化代码f数组开二维，其实只用到了f[0]

    while (k)
    {
        if (k & 1) mul(f, f, a);
        k >>= 1;
        mul(a, a, a);
    }

    int res = 0;
    for (int i = 0; i < m; i++) res = (res + f[0][i]) % mod;
    return res;
}

int main()
{
    cin >> n >> m >> mod;
    cin >> str + 1;

    //kmp
    for (int i = 2, j = 0; i < m; i++)
    {
        while (j && str[j + 1] != str[i]) j = ne[j];
        if (str[j + 1] == str[i]) j++;
        ne[i] = j;
    }

    for (int j = 0; j < m; j++)//当前长度是j
        for (int c = '0'; c <= '9'; c++)//枚举后一位添加的数字
        {
            int k = j;
            while (k && str[k + 1] != c) k = ne[k];
            if (str[k + 1] == c) k++;
            if (k < m) a[j][k]++;//添加完后一位后，与不吉利串的匹配长度是k，方案数++
        }

    cout << qmi(n) << endl;
    return 0;
}
