#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


void process(int n, const vector<int>& A, const vector<int>& B,
             vector<int>& res){

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    for(int i = 0; i < n; i ++) pq.push(make_pair(A[i] + B[0], make_pair(i, 0)));

    for(int index = 0; index < n; index ++){
        int v = pq.top().first, ai = pq.top().second.first, bi = pq.top().second.second;
        pq.pop();
        res[index] = v;

        if(bi + 1 < B.size()){
            pq.push(make_pair(A[ai] + B[bi + 1], make_pair(ai, bi + 1)));
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T --){
        int m, n; cin >> m >> n;

        vector<int> A(n), B(n), C(n);
        for(int i = 0; i < n; i ++) cin >> A[i];
        sort(A.begin(), A.end());

        for(int k = 1; k < m; k ++){

            for(int i = 0; i < n; i ++) cin >> B[i];
            sort(B.begin(), B.end());

            process(n, A, B, C);
            A = C;
        }

        for(int e: A) cout << e << ' ';
        cout << '\n';
    }
    return 0;
}
