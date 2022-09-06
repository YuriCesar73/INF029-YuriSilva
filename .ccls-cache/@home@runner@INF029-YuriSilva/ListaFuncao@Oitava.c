#include <stdio.h>
#include <string.h>
#define len 100

void cadastrarCliente (char nome [], char data [], char cpf[], char sexo []);
int main () {
  
  char data [len];
  char nome [len];
  char cpf [len];
  char sexo [len];

  //Função: Recebe os dados do cliente.
  cadastrarCliente(nome , data ,  cpf , sexo );

  //Saída dos dados
  printf("___________________________\n");
  printf("Os dados cadastrados foram: \n");
  printf("%s\n",nome);
  printf("%s\n",data);
  printf("%s\n",cpf);
  printf("%s\n",sexo);
  
}
  
void cadastrarCliente (char nome [],char data [], char cpf[],char sexo []) {

 int tamanho;

  //Nome
  printf("Digite o seu nome: \n");
  fgets (nome,len,stdin);
  tamanho= strlen (nome); 

		if (nome [tamanho-1]=='\n'){
        nome [tamanho-1]='\0';
      }

  //Data de Nascimento
  printf("Digite a sua data de nascimento: \n");
    fgets (data,len,stdin);
    tamanho= strlen (data); 

  		if (data [tamanho-1]=='\n'){
          data [tamanho-1]='\0';
        }

  //Cpf
  printf("Digite o seu cpf: \n");
    fgets (cpf,len,stdin);
    tamanho= strlen (cpf); 

  		if (cpf [tamanho-1]=='\n'){
          cpf [tamanho-1]='\0';
        }
  //Sexo
  printf("Digite o seu sexo: \n");
    fgets (sexo,len,stdin);
    tamanho= strlen (sexo); 

  		if (sexo [tamanho-1]=='\n'){
          sexo [tamanho-1]='\0';
        }  
  
  }






