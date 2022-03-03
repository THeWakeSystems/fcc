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
    n=10000;
    r=5000;
    cout<<n<<" "<<min(n*n,100000)<<endl;
	fclose(stdout);
	return 0;
} 

