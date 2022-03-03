#include<bits/stdc++.h>
using namespace std;
#define max(a,b) (((a) > (b)) ? (a) : (b))
 
#define min(a,b) (((a) < (b)) ? (a) : (b))
//  30%  1<=N<=100,
//  100% 1<=N<=80000,1<=a<=10 0000 0000.
bool map[1000][2000]={0};
int main(){
	freopen("in.txt", "w", stdout);
	
	srand((unsigned int)time(NULL)); //������� 

	int n=50000;
    cout<<n<<" 10000000"<<endl;
    for(int i=0;i<n;i++){
        cout<<rand()%10000000+1<<endl;
    }
	fclose(stdout);
	return 0;
} 

