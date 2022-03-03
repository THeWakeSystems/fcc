#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
const int N = 2020, M = 60;

int n;
vector<pair<int, PII>> routes;
int bus[M];

bool check(int a, int d) {
    for(int i=a; i<60; i+=d) {
        if(!bus[i]) return false;
    }
    return true;
}

bool dfs(int depth, int u, int sum, int start) {
    if(u == depth) return sum == n;
    if(routes[start].first * (depth - u) + sum < n) return false;
    for(int i=start; i<routes.size(); i++) {
        auto r = routes[i];
        int a = r.second.first, d = r.second.second;
        if(!check(a, d)) continue;
        for(int j=a; j<60; j+=d) bus[j]--;
        if(dfs(depth, u+1, sum+r.first, i)) return true;
        for(int j=a; j<60; j+=d) bus[j]++;
    }
    return false;
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        int t;
        cin >> t;
        bus[t]++;
    }
    for(int i=0; i<60; i++) {
        for(int j=i+1; i+j < 60; j++) {
            if(check(i, j)) {
                routes.push_back({(59-i)/j + 1, {i, j}});
            }
        }
    }
    
    sort(routes.begin(), routes.end(), greater<pair<int, PII>>());
    int depth = 0;
    while(!dfs(depth, 0, 0, 0)) depth++;
    
    cout << depth << endl;
    return 0;
    
}