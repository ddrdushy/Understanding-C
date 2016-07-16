#include <stdio.h>
void ptrFunction();
int main(){
	int a;
	int *add=&a;
	int **ab=&add;
	a=10;
	printf("A = %d\n",a);
	printf("A = %d\n",*add);
	printf("A = %d\n",**ab);
	ptrFunction();

	return 0;
}
