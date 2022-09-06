#include <stdio.h>

int resultadoFatorial (int n);


int main (){
  int n;
  int fat;
  
  printf("Digite o numero: \n");
  scanf("%d",&n);

  fat = resultadoFatorial (n);

  if (fat>0){
    printf("O fatorial do numero %d é %d\n",n,fat);
      }
  else if (fat<0){
    printf ("Não é possível realizar o fatorial desse número\n");
  }

}


int resultadoFatorial (int n){
  int fat;
  fat = 1;
  
    if (n>=0){
      for (int i=n;i>0;i--){
        fat = fat *i;
      }
    }
    else if (n<0){
      fat = -1;
    }

return fat;

  
}