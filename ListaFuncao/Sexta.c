#include <stdio.h>
#define TAM 3
void tresLetras(char vet[]);

int main()
{
    char meuVetor[3];
   
    tresLetras(meuVetor);
    
    printf("\n");
  
   for (int i=0;i<TAM;i++){
      printf("%c\n", meuVetor[i]);
   }
    
}

void tresLetras(char vet[])
{
int a=0;


  for (a=0;a<TAM;a++){
    printf("Digite uma letra: \n");
    scanf("%c",&vet[a]);
    getchar ();
    
  }
  
}