#include <stdio.h>

void mudarValores (int *a, int *b);

int main (void)
{
	int a, b;
	int *pa, *pb;
	
	pa = &a;
	pb = &b;

	printf("Digite o valor da variavel a: \n");
	scanf("%d",pa);
	printf("Digite o valor da variavel b: \n");
	scanf("%d",pb);
	

	printf("a: %d\n",a);
	printf("b: %d\n",b);

	printf("Depois da função: \n");
	
	mudarValores (pa, pb);

	printf("a: %d\n",a);
	printf("b: %d\n",b);
}

void mudarValores (int *a, int *b)
{
	int auxiliar;

	auxiliar = *b;
	*b = *a;
	*a = auxiliar;
}