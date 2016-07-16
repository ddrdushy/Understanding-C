#include <stdio.h>

int main(){
	int a;
	int *add=&a;
	int **ab=&add;
	a=10;
	printf("A = %d\n",a);
	printf("A = %d\n",*add);
	printf("A = %d",**ab);
	return 0;
}
