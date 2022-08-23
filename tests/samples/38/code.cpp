#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int number[200030]={0};

void a(int x){
	int j,i;
	for(i=6;i<=x;i++){
		int sum=1;
		for(j=2;j*j<i;j++){
			if(i%j==0) {
				sum=sum+j+i/j;
			}
		}
		if(j*j==i){
			sum+=j;
		}
		 number[i]=sum;
	}
}
int main ()
{
    int s;
    int s1;
    int s2;
    int k;
     a(90000);
     
	while(~scanf("%d",&s)){
		for(k=s;;k++){
			if(number[number[k]]==k&&number[k]!=k) {
				printf("%d %d\n",k,number[k]);
				break;
			}
		} 
	} 
	return 0; 
}