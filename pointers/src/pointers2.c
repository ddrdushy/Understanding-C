#include <stdio.h>

void ptrFunction(){
	char ch='c';
	char *chrptr=&ch;

	int i=20;
	int *intptr=&i;

	float f=4.526;
	float *floatptr=&f;

	char *ptr="Hello World";

	printf("%c\n",*chrptr);
	printf("%d\n",*intptr);
	printf("%f\n",*floatptr);
	printf("%c\n",*ptr);
	printf("%s\n",ptr);

}
