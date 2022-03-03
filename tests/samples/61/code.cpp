#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main()
{
    int n;
    cin >> n;
    set<int>s;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        s.insert(x);
        a[x]++;
    }
    set<int >::iterator it;
    for(it = s.begin(); it != s.end(); it++){
        if(a[*it]==1){
            cout << *it << endl;
            return 0;
        }
    }
    return 0;
}