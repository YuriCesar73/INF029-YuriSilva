#include <stdio.h>

int soma (int a, int b);

int  main (void){

  int a,b;
  int resultado;
  // Entrada de dados: ler os valores
  printf("Digite o primeiro numero: \n");
  scanf("%d",&a);
  printf("Digite o segundo numero: \n");
  scanf("%d",&b); 
  
  //Ida a função soma 
  resultado = soma (a, b);

  // Saída de dados
   
  printf("O resultado é: %d",resultado);

  
}

int soma (int a, int b){

int resultado; 
  //Processamento
  resultado = a+b;
  
  return resultado;
  
}