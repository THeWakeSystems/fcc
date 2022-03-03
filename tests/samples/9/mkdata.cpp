#include<bits/stdc++.h>
using namespace std;
#define max(a,b) (((a) > (b)) ? (a) : (b))
 
#define min(a,b) (((a) < (b)) ? (a) : (b))
//  30%  1<=N<=100,
//  100% 1<=N<=80000,1<=a<=10 0000 0000.
bool Map[5000][5000]={0};
int main(){
	freopen("in.txt", "w", stdout);
	
	srand((unsigned int)time(NULL)); //������� 
    int xi,yi,vi;
    int n,r;
    n=5000;
    cout<<n<<endl;
	long long r,c;
	r=c=500;
	cout<<r<<" "<<c<<endl;
    for(int _=0;_<n;_++){
		int p=1;
		while(p){
			int ii=rand()%500;
			int jj=rand()%500;
			if(Map[ii][jj]==0){
				Map[ii][jj]=1;
				cout<<ii<<" "<<jj<<" "<<rand()%3+1<<endl;
				p=0;
			}
		}
	}
	fclose(stdout);
	return 0;
} 

