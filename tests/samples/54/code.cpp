#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int len = s.size();
    if(len%2 == 0)
    {
        int ans = len/2;
        int ans2 = ans-1;
        for(int i = 0;i<len/2;i++)
        {
            if(s[ans] != s[ans2])
            {
                cout << "NO" <<endl;
                return 0;
            }else
            {
                ans++;
                ans2--;
            }
        }
    }else
    {
        int mid = len/2;
        for(int i = 1;i<=len/2;i++)
        {
            if(s[mid-i] != s[mid+i])
            {
                cout << "NO"<<endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}