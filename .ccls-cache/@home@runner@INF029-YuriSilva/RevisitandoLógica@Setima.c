#include <stdio.h>
/*Faça um programa que verifique se um número é primo*/
int main (){
  
  int n,count;
  
    count=0;
  
      printf("Digite o numero: \n");
      scanf("%d",&n);
  
      for(int i = n-1; i>=1;i--){
        if (n%i==0){
          count++;
        }
      }
  
      if(count==1){
        printf("O número %d é primo",n);
      }
      else {
        printf("O número %d não é primo",n);
      }
  
}