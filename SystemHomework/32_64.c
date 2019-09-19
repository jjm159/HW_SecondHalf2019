#include <stdio.h>


int main()
{
	int *p;

	if(sizeof(p) == 8) printf("64bit\n");
	else if (sizeof(p) == 4) printf("32bit\n");
	else printf("I don't know\n");

	return 0;
}
