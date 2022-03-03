#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    if (n % 2 == 1 || n == 0){
        cout<<"qiandaoshibai";
    }
    else if (n % 2 == 0){
        cout<<"qiandaochenggong";
    }
}