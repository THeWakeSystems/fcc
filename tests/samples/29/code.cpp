#include<stdio.h>
int main(){
    int n = 0, i=0, t=0;
    scanf("%d", &t);
    while (t--){
		scanf("%d", &n);
		i=0;
		while (n != 1){
			if (n % 2 == 0)
				n = n / 2;
			else {
				n--;
			}
			i++;
		}
		printf("%d\n", i);
    }
    return 0;
}