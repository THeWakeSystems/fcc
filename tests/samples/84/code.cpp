#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
#define ll long long 
#define N 1000010
int n , tot , P = 99991 ;
int snow[N][6] , head[N] ,next1[N] ;
int H (int *a){
    int sum = 0 , mul = 1;
    for (int i = 0; i < 6; i++){
        sum = (sum + a[i]) % P;
        mul = (long long) mul * a[i] % P;
    }
    return (sum + mul) % P ;
}
bool equal(int *a, int *b){
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 6; j++){
            bool eq = 1;
            for (int k = 0; k < 6; k++){
                if (a[(i+k)%6] != b[(j+k)%6]) eq = 0;
            }
            if (eq) return 1;
            eq = 1;
            for (int k = 0; k < 6; k++){
                if (a[(i+k) % 6] != b[(j-k+6)%6]) eq = 0;
            }
            if (eq) return 1 ;
        }
    }
    return 0 ;
}
bool insert(int *a){
    int val = H(a) ;
    for (int i = head[val] ; i; i = next1[i]) {
        if (equal(snow[i], a)) return 1;
    }
    ++tot ;
    memcpy(snow[tot], a, 6* sizeof(int)) ;
    next1[tot] = head[val];
    head[val] = tot ;
    return 0; 
}
int main(){
    cin >> n;
    int jk = 0 ;
    for (int i = 1; i <= n; i++){
        int a[10];
        for (int j = 0; j < 6; j++) scanf("%d",&a[j]);
        if (insert(a)){
            if (jk == 0){
                puts("Twin snowflakes found.");
               jk = 1;
            }
        }
    }
    if (jk == 0)
    puts("No two snowflakes are alike.");
    return 0;
}