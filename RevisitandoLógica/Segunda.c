# include <stdio.h>
/*Faça um programa que leia a idade de duas pessoas e imprima a soma das idades*/
int main (){
  
  int idade1, idade2,soma;
  soma=0;
  
  //Entrada de dados
  printf("Digite a idade 1: \n");
  scanf("%d",&idade1);
  printf("Digite a idade 2: \n");
  scanf("%d",&idade2);

  //Processamento
  soma=idade1+idade2;
  
  //Saida
  printf("A soma das idades eh: %d",soma);
}