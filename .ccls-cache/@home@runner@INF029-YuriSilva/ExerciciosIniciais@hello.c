#include <stdio.h>
#include <string.h>


typedef  struct {

  int dia;
  int mes;
  int ano;
} data;

int main(){

  data nascimento;

  printf("Digite o dia do nascimento: \n");
  scanf("%d",&nascimento.dia);

  printf("Digite o mês do nascimento: \n");
  scanf("%d",&nascimento.mes);

  printf("Digite o ano do nascimento: \n");
  scanf("%d",&nascimento.ano);


  printf("\n______________________________________\n");

  printf("%d/",nascimento.dia);
  printf("%d/",nascimento.mes);
  printf("%d",nascimento.ano);
}
