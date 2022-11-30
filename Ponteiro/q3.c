#include <stdio.h>
#define tam 5

void ordenarValores (int vetor []);

int main (void)
{
	int vetor[tam], i;
	int *p;
	p = vetor;

	for (i = 0; i < tam; i++)
		{
			printf("Digite o numero %d: \n",i);
			scanf("%d",p+i);
		}

	ordenarValores (vetor);

	for (i = 0; i < tam; i++) printf("%d ",vetor[i]);
}

void ordenarValores (int vetor []){

	int i, j, auxiliar;
	
	for (i = 0; i < tam - 1; i++){
		for (j = i + 1; j < tam; j++){
			if (vetor[i] > vetor[j]){
				auxiliar = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = auxiliar;
			}
		}
	}
	
}
