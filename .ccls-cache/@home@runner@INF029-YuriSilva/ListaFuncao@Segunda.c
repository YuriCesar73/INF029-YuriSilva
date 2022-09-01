#include <stdio.h>

int subtrai (int a, int b, int c);

int main(){

  int a,b,c;
  int resultado;

  printf("Digite o primeiro numero: \n");
  scanf("%d",&a);
  printf("Digite o segundo numero: \n");
  scanf("%d",&b);
  printf("Digite o terceiro numero: \n");
  scanf("%d",&c);
  
  resultado = subtrai (a, b, c);
  
  printf("O resultado é: %d",resultado);


  
}


int subtrai (int a, int b, int c){

  int resultado;
  resultado = a-b-c;

  return resultado;
}