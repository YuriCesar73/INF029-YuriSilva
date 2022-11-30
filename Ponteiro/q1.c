#include <stdio.h>

int main (void){

	int i;
	int *pInt;
	pInt = &i;
	
	//Leitura inteiro
	scanf("%d",pInt);
	//Impressão inteiro
	printf("%d",i);

	float f;
	float *pFloat = &f;

	//Leitura float
	scanf("%f",pFloat);
	//Impressão float
	printf("%f",f);

	char c;
	char *pChar = &c;

	//Leitura char
	scanf("%c",pChar);
	//Impressão
	printf("%c",c);

	/*double d;
	double *pDouble = &d;

	//Leitura double
	//Impressão*/

	char String[10];
	char *pString = String;

	//Leitura
	scanf("%s",pString);
	//Impressão
	printf("%s",String);

	int Vetor[5];
	int *pVetor;
	
}




















/*
int main(void)
{
	//valor é a variável que
	//será apontada pelo ponteiro
	int valor = 27;
	
	//declaração de variável ponteiro
	int *ptr;

	//declaração de ponteiro de ponteiro
	int **pptr;
	
	
	//atribuindo o endereço da variável valor ao ponteiro
	ptr = &valor;
	pptr = &ptr;
	
	printf("Utilizando ponteiros\n\n");
	printf ("Conteudo da variavel valor: %d\n", valor);
	printf ("Endereço da variavel valor: %x \n", &valor);
	printf ("Conteudo da variavel ponteiro ptr: %x\n", ptr);
	printf("Conteudo da variavel para qual o ponteiro aponta: %d\n",*ptr);

	printf ("Conteudo da variavel ponteiro de ponteiro pptr: %x\n", pptr);
	printf("Conteudo da variavel para qual o ponteiro de ponteiro aponta: %d\n",**pptr);
	
	
	
	
	return(0);
}*/