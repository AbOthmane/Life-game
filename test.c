#include <stdlib.h>
#include <stdio.h>
int main()
{
	srand(453354);
	for(int i=0;i<100;i++){
	int a = (rand()%100<=10)? 1 : 0;

	printf("%d",a);}
	return 0;
}	