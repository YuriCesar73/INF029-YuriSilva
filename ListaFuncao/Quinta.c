#include <stdio.h>

typedef struct{
  int n1;
  int n2;
  int n3;
  int n4;
} numeros;

numeros ler ( );

int main (){

int i;
int a;
numeros n;

  

  /*printf("Digite o numero: \n);
  scanf("%d",&a);
  n.n1=a;

  printf("Digite o numero\n");
  scanf("%d",&a);
  n.n2=a;

  printf("Digite o numero\n");
  scanf("%d",&a);
  n.n3=a;

  printf("Digite o numero\n");
  scanf("%d",&a);
  n.n4=a;*/

  n=ler();


printf("%d\n",n.n1);
printf("%d\n",n.n2);
printf("%d\n",n.n3);
printf("%d\n",n.n4);
  
}


numeros ler ( ){

  int a;
  numeros n;
  
  printf("Digite o numero: \n");
  scanf("%d",&a);
  n.n1=a;

  printf("Digite o numero\n");
  scanf("%d",&a);
  n.n2=a;

  printf("Digite o numero\n");
  scanf("%d",&a);
  n.n3=a;

  printf("Digite o numero\n");
  scanf("%d",&a);
  n.n4=a;

return n;

  
}