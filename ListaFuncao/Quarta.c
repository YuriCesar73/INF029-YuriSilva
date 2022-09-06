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
    printf("%d\n", meuVetor[0]);
    printf("%d\n", meuVetor[1]);
    printf("%d\n", meuVetor[2]);
    printf("%d\n", a);
}

void tresNumeros(int a, int vet[])
{

    vet[0] = 45;
    vet[1] = 2;
    vet[2] = 3;
    a = 15;
}