#include <stdio.h>

void tresNumeros(int a, int vet[]);

int main()
{
    int meuVetor[3];
   /*meuVetor[0] = 99;
    meuVetor[1] = 22;
    meuVetor[2] = 33;*/
  
    int a = 10;
    tresNumeros(a, meuVetor);
    printf("\n");
    printf("%d\n", meuVetor[0]);
    printf("%d\n", meuVetor[1]);
    printf("%d\n", meuVetor[2]);
    
}

void tresNumeros(int a, int vet[])
{

  for (int i=0;i<3;i++){
    printf("Digite o numero: \n");
    scanf("%d",&vet[i]);
  }
   
}