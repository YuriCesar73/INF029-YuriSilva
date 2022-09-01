# include <stdio.h>
/*Faça um programa que leia dois valores informados pelo usuário e inverta os valores nas variáveis lidas*/
int main (){

  int a, b, n;

  //Entrada de dados
  printf("Digite o primeiro valor: \n");
  scanf("%d",&a);
  printf("Digite o segundo valor: \n");
  scanf("%d",&b);

  //Processamento
  n = a;
  a = b;
  b = n;
  
  //Saida
  printf("Os valores invertidos sao: a = %d e b = %d",a,b);
  
}