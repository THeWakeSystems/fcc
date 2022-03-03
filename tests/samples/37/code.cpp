#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int c[100010],d[100010];
long long e;
string a,b;
int main() {
	cin>>a>>b;
	for(int i=0;i<a.size();i++){
		c[i]=a[i]-'0';
	}
	for(int i=0;i<b.size();i++){
		d[i]=b[i]-'0';
	}
	if(a.size()>=b.size()){
		for(int i=0;i<a.size();i++){
			for(int j=0;j<b.size();j++){
				e=e+c[i]*d[j];
			}
		}
	}
	if(a.size()<b.size()){
		for(int i=0;i<b.size();i++){
			for(int j=0;j<a.size();j++){
				e=e+d[i]*c[j];
			}
		}
	}
	cout<<e;
	return 0;
}