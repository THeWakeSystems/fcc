
#include <bits/stdc++.h>
using namespace std;

#define long long long
#define N 100010

long a[N];
  long p=10007;
long exgcd(long a, long b, long &x, long &y)
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    long r = exgcd(b, a%b, x, y);
    long tmp = x;
    x = y;
    y = tmp - a / b * y;
    return r;
}

long C(long n, long m)
{
    if(n < m)
        return 0;
    long x, x1, y, y1;
    exgcd(a[m], p, x, y);
    exgcd(a[n-m], p, x1, y1);
    x = (x + p) % p;
    x1 = (x1 + p) % p;
    return ((a[n] % p) * x % p * x1 % p) % p;
}

long Lucas(long n, long m)
{
    if(!m)
        return 1;
    return C(n % p, m % p) * Lucas(n / p, m / p) % p;
}

int main()
{
    int t;
    cin >> t;
  
    while(t--)
    {
        long n, m;
        cin >> n >> m ;
    
        a[0] = 1;
        for(int i = 1; i <= p; i++)
        {
            a[i] = (a[i-1] * i) % p;
        }
        cout << Lucas(n,m) << endl;
    }
    return 0;
}

