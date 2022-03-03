#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1e6 + 5;
char a[N];
int n,Next[N],t;
int main(){
    while(scanf("%d",&n),n){
        scanf("%s",a + 1);
        printf("Test case #%d\n",++t);
        for(int i = 2, j = 0; i <= n; i ++){
            while(j > 0 && a[i] != a[j + 1])j = Next[j];
            if(a[i] == a[j + 1])j++;
            Next[i] = j;
        }

        for(int i = 2; i <= n; i++){
            int t = i - Next[i];
            if(t != i && i % t == 0)
                printf("%d %d\n", i, i / t); }
        puts("");}
    return 0;}
