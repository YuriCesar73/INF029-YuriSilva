# include <stdio.h>
/*Faça um programa que leia a idade de uma pessoa e informe de ela é de maior ou menor*/
int main (){

  int idade;

  //Entrada de dados
  printf("Informe a idade: \n");
  scanf("%d",&idade);

  //Processamento e Saída
  if (idade < 18){
    printf("Você é menor de idade");
  }
  else {
    printf("Você é maior de idade");
    
  }

  
}