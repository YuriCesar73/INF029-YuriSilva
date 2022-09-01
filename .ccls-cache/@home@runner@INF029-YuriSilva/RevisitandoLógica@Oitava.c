# include <stdio.h>
/*Faça um programa que calcula o fatorial de um número*/
int main (){
  int n;
  int fatorial;
    
  fatorial=1;

  //Entrada de dados
    printf("Digite o numero para ver seu fatorial\n");
    scanf("%d",&n);

  //Processamento
    for(int i=n;i>=1;i--){
  
      fatorial=fatorial*i;
    }

  //Saída de dados
    printf("O fatorial é: %d",fatorial);


  
}