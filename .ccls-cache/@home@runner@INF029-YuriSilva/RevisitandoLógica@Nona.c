#include <stdio.h>
# define TAM 10
/*Faça um programa que leia 10 números do usuário e informe quais deles são primos. Além disso, mostre a soma de todos os números primos existentes.*/

int main(){
  int numeros[TAM];
  int primos[TAM];
  
  
  for (int i = 0; i < TAM; i++){
    primos[i] = 1;
  }

  for (int i = 0; i < TAM; i++){
    printf("Digite o número %d: ", i);
    scanf("%d", &numeros[i]);
  }

  for (int i = 0; i < TAM; i++){
    for (int j = 2; j < numeros[i]; j++)
      if (numeros[i] % j == 0){
        primos[i] = 0;
        break;
      }
  }
  
  int soma = 0;
  printf("Os números primos são: ");
  for (int i = 0; i < TAM; i++){
    if (primos[i] == 1){
      soma = soma + numeros[i];
      printf("%d, ", numeros[i]);
    }
  }
  printf("\nA soma é: %d", soma);
}
  