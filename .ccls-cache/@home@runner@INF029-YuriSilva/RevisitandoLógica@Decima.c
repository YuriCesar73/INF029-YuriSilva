# include <stdio.h>
# include <string.h>
# define tam 2
/*Faça um programa que leia os dados de nome, idade, sexo e cpf de 5 pessoas. Ao final imprima tudo. 
Utilize vetor e struct.*/

int main (){
	
int i;	
int tamanho;
struct ficha {
	char nome [tam] [256];
	char idade [tam] [256];
	char sexo [tam] [256];
	char cpf [tam] [256];
	
};	
	
struct ficha cadastro;


for (i=0;i<tam;i++){
	printf("Digite o seu nome: ");
	fgets (cadastro.nome[i],256,stdin);
	tamanho = strlen (cadastro.nome[i]-1);
	
		if (cadastro.nome [i] [tamanho]=='\n'){
      cadastro.nome [i] [tamanho]='\0';
    }
												
	printf("Digite sua idade: ");
	fgets (cadastro.idade[i],256,stdin);
	tamanho = strlen (cadastro.idade[i]-1);
	
		if (cadastro.idade [i] [tamanho]=='\n'){
      cadastro.idade [i] [tamanho]='\0';
    }
												
	printf("Digite seu sexo: ");
	fgets (cadastro.sexo[i],256,stdin);
	tamanho = strlen (cadastro.sexo[i]-1);
	
		if (cadastro.sexo [i] [tamanho]=='\n'){
      cadastro.sexo [i] [tamanho]='\0';
    }
												
	printf("Digite seu cpf: ");
	fgets (cadastro.cpf[i],256,stdin);
	tamanho = strlen (cadastro.cpf[i]-1);
	
		if (cadastro.cpf [i] [tamanho]=='\n'){
      cadastro.cpf [i] [tamanho]='\0';
    }
												
}

for (i=0;i<tam;i++){
	printf("%s",cadastro.nome[i]);
	printf("%s",cadastro.idade[i]);
	printf("%s",cadastro.sexo[i]);
	printf("%s",cadastro.cpf[i]);

}

return (0);




}
