#include <bits/stdc++.h>

using namespace std;
string s[] = {"0", "0", "01", "", "1001", "10001", "011001", "0101001"};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >>n;
    if(n==3)cout <<"Unlucky\n";
    else {
        if(n<=7)cout <<s[n]<<endl;
        else {
            int ans=0;
            if(n%4==0)ans=n/4;
            else if(n%4==1) {
                cout <<s[5];
                ans=n/4-1;
            } else if(n%4==2) {
                cout <<s[2];
                ans=n/4;
            } else {
                cout <<s[7];
                ans=n/4-1;
            }
            while(ans--)cout <<"1001";
            cout <<endl;
        }
    }
    return 0;
}
