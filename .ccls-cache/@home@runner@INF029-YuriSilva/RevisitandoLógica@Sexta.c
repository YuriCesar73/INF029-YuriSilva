# include <stdio.h>
/*Faça um programa que leia a idade de uma pessoa e informe de ela é de maior ou de menor. O programa deve repetir essa ação até que uma idade negativa seja informada*/
int main (){

  int idade;
  
    do {
          printf("\nInforme a sua idade: \n");
          scanf("%d",&idade);
  
          if(idade<18 && idade>=0){
          printf("Você é de menor\n");
          }
            
          else if (idade >=18){
          printf("Você é de maior\n");
          }
  
    } while (idade>=0);

  
}