#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int N = 1e4 + 10;
int n, m;

int p[N], st[N], idx;
void line_prim(int x) {
	for(int i = 2; i <= x; i ++ ) {
		if(!st[i]) p[idx ++ ] = i;
		for(int j = 0; p[j] <= x / i; j ++ ) {
			st[p[j] * i] = 1;
			if(i % p[j] == 0) break;
		}
	}
}

int get(int a, int p) {
	int res = 0;
	while(a) {
		res += a / p;
		a /= p;
	}
	return res;
}

vector<int> cnt(int a, int b) {
	vector<int> res;
	for(int i = 0; i < idx; i ++ ) {
		res.push_back(get(a, p[i]) - get(b, p[i]) - get(a - b, p[i]));
	}	
	return res;
}

vector<int> mul(vector<int> A, int b) {
    vector<int> res;
    int t = 0;

    for(int i = 0; i < A.size() || t; i ++ ) {
        if(i < A.size()) t += A[i] * b;

        res.push_back(t % 10);
        t /= 10;
    }

    if(res.size() > 1 && res.back() == 0) res.pop_back();
    return res;
}

vector<int> calc(vector<int> x) {
	vector<int> res; res.push_back(1);
	for(int i = 0; i < idx; i ++ ) {
		for(int j = 0; j < x[i]; j ++ ) {
			res = mul(res, p[i]);
		}
	}
	return res;
}

vector<int> sub(vector<int> &A, vector<int> &B){

    int t = 0; 
    vector<int> res;
    for(int i = 0; i < A.size(); i ++ ){
        t = A[i] - t; 
        if(i < B.size()) t -= B[i];

        res.push_back((t+10)%10);  
        if(t >= 0) t = 0;   
        else  t = 1;       
    }

    while(res.size() > 1 && res.back() == 0) res.pop_back();  

    return res;
}

int main() {
	cin >> n >> m;
	line_prim(n + m);
	vector<int> cnt1 = cnt(n + m, n);
	vector<int> cnt2 = cnt(n + m, m - 1);
	vector<int> C2 = calc(cnt2), C1 = calc(cnt1);
	
	vector<int> ans = sub(C1, C2);
	for(int i = ans.size() - 1; i >= 0; i -- ) cout << ans[i];
	cout << endl;
	
	return 0;
}