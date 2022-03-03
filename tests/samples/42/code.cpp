#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int n;
    string oppo;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>oppo;
        if (oppo == "Rock"){
            cout<<"Paper\n";
        }
        else if (oppo == "Scissors"){
            cout<<"Rock\n";
        }
        else if (oppo == "Paper"){
            cout<<"Scissors\n";
        }
    }
}