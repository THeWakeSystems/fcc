/*
ID: s_hpliu
PROG: rectbarn
LANG: C++14
*/
#include<bits/stdc++.h>
using namespace std;


int main() {
  int R, C, P; cin >> R >> C >> P;
  map<int, vector<int> > M;
  for (int i = 0; i < P; i++) {
    int x, y; cin >> x >> y;
    M[x].push_back(y);
  }
  vector<int> A(C+2);
  A[0] = -1;
  A[C+1] = 0;
  int best = 0;
  for (int r = 1; r <= R; r++) {
    for (int c = 1; c <= C; c++) A[c]++;
    for (auto c: M[r]) A[c] = 0;
    stack<int> S;
    // cout << "====" << r << endl;
    // for (int c = 0; c <= C + 1; c++) cout << A[c] << " " ;
    // cout << endl;
    for (int i = 0; i <= C+1; i++) {
      while (S.size() && A[S.top()] > A[i]) {
        int k = A[S.top()];
        S.pop();
        best = max(best, (i - S.top() - 1) * k) ;
        // cout << i << " " << S.top() << " " << (i - S.top() - 1) * k << endl;
      }
      S.push(i);
    }
  }
  cout << best << endl;
}