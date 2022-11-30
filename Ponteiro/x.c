#include <stdio.h>

int main()
{
	//No caso do vetor, não é necessário usar o & para ter o endereço da sua memória porque o vetor (sem o índice) já é sua posição de memória (já é um ponteiro).
	
	int vetorInt[6]; //declara o vetor 
	int *pVetor = vetorInt; // declara o ponteiro, já apontando para o vetor
	int inteiro = pVetor[5]; // a variável inteiro recebe o valor do índice 5 no vetor


	inteiro = *(pVetor+5); // É o equivalente à declaração feita acima
	inteiro = (pVetor+5); //Estaria pegando o endereço de memória do indice 5 do vetor

	int *p3[5]; // declaração de um vetor de ponteiros. Ou seja, eu armazeno ponteiros do tipo que eu declaro (pego apenas endereços)
	
	p3[0] = vetorInt; // peguei o endereço
	p3[3] = &vetorInt[2]; // peguei o endereço
	p3[2] = pVetor + 2; //peguei o endereço
	
	
	
	
	
	
}
