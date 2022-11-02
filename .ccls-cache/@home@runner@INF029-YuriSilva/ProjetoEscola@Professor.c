#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "Disciplina.h"
#include "Professor.h"
#include "Aluno.h"
#include "Valida.h"
#define anoAtual 2022
#define QTD_Professores 100

// static int PRcad = 0;

Professores listaProfessores(Professores cadastro[]);
int excluiProfessores(Professores cadastro[]);
int atualizaProfessores(Professores cadastro[]);
void ordenaSexoProf(Professores cadastro[]);
void ordenaNomeProf (Professores cadastro[]);
void ordenaDataProf(Professores cadastro[]);

int validaCpf(char cpf[]);
int validaSexo(char sexo[]);
int validarNascimento(char dataNasc[]);
int matriculaProfessor ( );

int cadastroProfessores(Professores cadastro[]) {

	int tamanho;
	char s[10];
	/*sobre a variavel acima: i é o índice dos alunos cadastrados. */
	
	int validadeCpf;  // -1 = inválido, 1 = válido
	int validadeData; // -1 = inválido, 0 = válido, data de nascimento (essa validade é igual a 0, diferente da anterior e da próxima)
	int validadeSexo; // -1 = inválido, 1 = válido
	int validadeMatricula; // -1 = inválido, 1 = válido
	int op = 1; // essa variavel sera usada para definir a continuidade ou nao do
			  // programa, a depender da resposta do usuario. 0 = encerrar, 1 =
			  // continuar
	
	while (op == 1) {

	    fflush(stdin);
	
	    printf("\nNome: ");
	    fgets(cadastro[PRcad].nome, 101, stdin);
	
	    cadastro[PRcad].nome[strcspn(cadastro[PRcad].nome, "\n")] = 0;
	
	    printf("\nCPF (apenas numeros): ");
	    fgets(cadastro[PRcad].cpf, 20, stdin);
	    cadastro[PRcad].cpf[strcspn(cadastro[PRcad].cpf, "\n")] = 0;
	    validadeCpf = validaCpf(cadastro[PRcad].cpf);
	
	    while (validadeCpf == -1) {
			fflush(stdin);
			printf("\nCPF invalido! Tente novamente: ");
			fgets(cadastro[PRcad].cpf, 20, stdin);
			cadastro[PRcad].cpf[strcspn(cadastro[PRcad].cpf, "\n")] = 0;
			validadeCpf = validaCpf(cadastro[PRcad].cpf);
	    }
	
	    fflush(stdin);
	    printf("\nSexo: ");
	    fgets(cadastro[PRcad].sexo, 20, stdin);
	    // getchar();
	    // cadastro[i].sexo[strcspn(cadastro[i].sexo, "\n")] = 0;
	    tamanho = strlen(cadastro[PRcad].sexo);
	    if (cadastro[PRcad].sexo[tamanho - 1] == '\n') {
	    	cadastro[PRcad].sexo[tamanho - 1] = '\0';
	    }
	    validadeSexo = validaSexo(cadastro[PRcad].sexo);
	
	    printf("\nData de nascimento [dd/mm/aaaa]: ");
	    fgets(cadastro[PRcad].data, 12, stdin);
	    cadastro[PRcad].data[strcspn(cadastro[PRcad].data, "\n")] = 0;
	    char copia[12];
		
	    for(int count = 0; cadastro[PRcad].data[count] != '\0'; count++)
	    	copia[count] = cadastro[PRcad].data[count];
		
	    validadeData = validarNascimento(copia);
	    		/*o if abaixo serve para evitar que o vetor fique "pouluído" quando o usuário digita mais caracteres do que o permitido na data. Observe que ele se repete no próximo laço while*/
	    if (validadeData == -1)
		{
			fflush(stdin);
			for (int count = 0;count<12;count++)
			{
				cadastro[PRcad].data[count] = '\0';
				copia[count]=cadastro[PRcad].data[count];
			}
		}
	    
	    while(validadeData == -1)
	    {
			fflush(stdin);
			printf("\nData ou formato invalido! Tente novamente: ");
			fgets(cadastro[PRcad].data, 12, stdin);
			cadastro[PRcad].data[strcspn(cadastro[PRcad].data, "\n")] = 0;
			
			for(int count = 0; cadastro[PRcad].data[count] != '\0'; count++)
				copia[count] = cadastro[PRcad].data[count];
			
			validadeData = validarNascimento(copia);
			if (validadeData == -1)
			{
				fflush(stdin);
				for (int count = 0;count<12;count++)
				{
					cadastro[PRcad].data[count] = '\0';
					copia[count]=cadastro[PRcad].data[count];
				}
			}
	    }


		cadastro[PRcad].matricula = matriculaProfessor ( );
		printf("\nSua matricula gerada foi: %ld\n", cadastro[PRcad].matricula);
		
		/*printf("\nMatricula: ");
	    scanf("%ld", &cadastro[PRcad].matricula);
	    getchar();*/
		

	    printf("\nDeseja realizar outro cadastro?\n[1] Sim\n[0] Nao\n");
	    scanf("%d", &op);
	    getchar();
	
	    while (op != 1 && op != 0) {
	    	printf("\nOpcao invalida! Tente novamente: ");
	    	scanf("%d", &op);
	    	getchar();
	    }
	    if (op == 1) {
	    	PRcad++;
	    }
  	}

  	PRcad++;
	return PRcad;
}

Professores listaProfessores(Professores cadastro[]) {
	printf("\n\tTodos os professores\n\n");
	
	for (int j = 0; j < PRcad; j++) {
		printf("Nome........: %s\n", cadastro[j].nome);
		printf("Matricula...: %ld\n", cadastro[j].matricula);
		printf("CPF.........: %s\n", cadastro[j].cpf);
		printf("Sexo........: %c\n", cadastro[j].sexo[0]);
		printf("Nascimento..: %s\n", cadastro[j].data);
		printf("\n");
	}
}

void ordenaSexoProf(Professores cadastro[]){

	printf("Sexo Masculino: \n\n");
	for (int j = 0; j < PRcad; j++) {
		if(cadastro[j].sexo[0] == 'M'){
			printf("Nome........: %s\n", cadastro[j].nome);
			printf("Matricula...: %ld\n", cadastro[j].matricula);
			printf("CPF.........: %s\n", cadastro[j].cpf);
			printf("Sexo........: %c\n", cadastro[j].sexo[0]);
			printf("Nascimento..: %s\n", cadastro[j].data);
			printf("\n");
		}
	}

	printf("Sexo Feminino: \n\n");
	for (int j = 0; j < PRcad; j++) {
		if(cadastro[j].sexo[0] == 'F'){
			printf("Nome........: %s\n", cadastro[j].nome);
			printf("Matricula...: %ld\n", cadastro[j].matricula);
			printf("CPF.........: %s\n", cadastro[j].cpf);
			printf("Sexo........: %c\n", cadastro[j].sexo[0]);
			printf("Nascimento..: %s\n", cadastro[j].data);
			printf("\n");
		}
	}

	printf("Outros: \n\n");
	for (int j = 0; j < PRcad; j++) {
		if(cadastro[j].sexo[0] == 'O'){
			printf("Nome........: %s\n", cadastro[j].nome);
			printf("Matricula...: %ld\n", cadastro[j].matricula);
			printf("CPF.........: %s\n", cadastro[j].cpf);
			printf("Sexo........: %c\n", cadastro[j].sexo[0]);
			printf("Nascimento..: %s\n", cadastro[j].data);
			printf("\n");
		}
	}
}

void ordenaNomeProf (Professores cadastro[]){

	int i, j;
	char letra [1];
	letra [0] = 'A';
	
	for (i=0;i <= 25; i++)
		for (j = 0; j < PRcad; j++){
			if (cadastro[i].nome[0] >= 97 && cadastro[i].nome[0] <= 122){
				cadastro[i].nome[0] = cadastro[i].nome[0] - 32;
			}
			if (cadastro[j].nome[0] == letra[0] + i){
				printf("\n");
				printf("Nome.............: %s\n",cadastro[j].nome);
				printf("Matricula........: %ld\n",cadastro[j].matricula);
				printf("Cpf..............: %s\n",cadastro[j].cpf);
				printf("Sexo.............: %s\n",cadastro[j].sexo);
				printf("Nascimento.......: %s\n",cadastro[j].data);
			}
		}		
}

void ordenaDataProf(Professores cadastro[]){

	int i, j, k, l, auxiliar, Ano, Mes, Dia;
	char aux [PRcad] [12];
	int dataInt, ano[PRcad], mes[PRcad], dia[PRcad];
	
	k = 0;
	
	for(j = 0; j < PRcad ; j++)
	{
		for (i = 0;  cadastro[j].data[i] != '\0'; i++)
			{	
				if (cadastro[j].data[i] >= 48 && cadastro[j].data[i] <= 57)
				{
					aux [j] [k] = cadastro[j].data[i];	
					k++;
				}
			}
			aux [j] [k] = '\0';
			k=0;
			dataInt = atoi(aux [j]);
			
			//Armazena todos os anos, meses e dias recebidos
			ano[j] = dataInt % 10000;
			mes [j] = (dataInt / 10000) % 100;
			dia [j] = dataInt / 1000000;
	}
	
	//ordena os anos
	for (i = 0 ; i <PRcad; i++ ){
		for (j = 0; j < PRcad; j++){
			if (ano[i] < ano [j]){
				auxiliar = ano [i];
				ano[i] = ano[j];
				ano[j] = auxiliar;
			}
		}
	}
	//ordena os meses;
	for (i = 0 ; i <PRcad; i++ ){
		for (j = 0; j < PRcad; j++){
			if (mes[i] < mes [j]){
				auxiliar = mes [i];
				mes[i] = mes[j];
				mes[j] = auxiliar;
			}
		}
	}
	// Ordena os dias;
	for (i = 0 ; i <PRcad; i++ ){
		for (j = 0; j < PRcad; j++){
			if (dia[i] < dia [j]){
				auxiliar = dia [i];
				dia[i] = dia[j];
				dia[j] = auxiliar;
			}
		}
	}

	for (i = 0; i<PRcad; i++){
		for(j = 0; j< PRcad; j++){
			for (k=0; k < PRcad; k++){
				for (l = 0; l<PRcad; l++){
					dataInt = atoi (aux [l]);
					Mes = (dataInt / 10000) % 100;
					Dia = dataInt / 1000000;
					Ano = dataInt % 10000;

					if(Dia == dia[k] && Mes == mes[j] && Ano == ano[i]){
						printf("Nome...........: %s\n",cadastro[l].nome);
						printf("Matricula......: %ld\n",cadastro[l].matricula);
						printf("CPF............: %s\n",cadastro[l].cpf);
						printf("Sexo...........: %s\n",cadastro[l].sexo);
						printf("Nascimento.....: %s\n",cadastro[l].data);
						printf("\n");
						dia[k] = 0;
						mes[j] = 0;
						ano[i] = 0;
						aux[l] [0] = '\0'; 
						k = j = i = 0;
						for (int a = 0; a < 8; a++) aux[l] [a] = '9';
						aux [l] [8] = '\0';
					}
				}
			}
		}
	}
}

int excluiProfessores(Professores cadastro[]){
	char cpfRemover[20];
	int i, j;
	int op, confirma;
	int flag; // verifica se o cpf existe no registro ou nao 

	op = 1;
	while(op == 1){
	    printf("\nDigite o CPF da pessoa que deseja excluir: ");
	    fgets(cpfRemover, 20, stdin);
		cpfRemover[strcspn(cpfRemover, "\n")] = 0;

	    for(i = 0; i < PRcad; i++){
			flag = 0;
	        if(strcmp(cadastro[i].cpf, cpfRemover) == 0){
				flag = 1;
					
				if(flag == 0){
					printf("\nO CPF informado nao esta registrado no sistema.");
					break;
				}
	
				else{
		            printf("\nExcluir professor(a) %s?\n[1] Sim\n[2] Nao\n", cadastro[i].nome);
					scanf("%d", &confirma);
					if(confirma == 1){
						for (j = i; j < PRcad; j++){
		                	strcpy(cadastro[i].nome, cadastro[i + 1].nome);
							cadastro[i].matricula = cadastro[i + 1].matricula;
							strcpy(cadastro[i].cpf, cadastro[i + 1].cpf);
							strcpy(cadastro[i].sexo, cadastro[i + 1].sexo);
							strcpy(cadastro[i].data, cadastro[i + 1].data);
		                	i++;
						}
						printf("\nCadastro excluido com sucesso\n");
						PRcad--;
					}
					else{
						printf("\nCadastro nao excluido\n");
						break;
					}
				}
	    	}
		}

		op = -1;
		while(op != 1 && op != 0){
			printf("\nDeseja excluir outro cadastro?\n[1] Sim\n[0] Nao\n");
			scanf("%d", &op);
			getchar();
		}
	}
return PRcad;
}

int atualizaProfessores(Professores cadastro[]){
	char cpfAtt[20];
	int flag;
	int i, j, confirma;
	int op;
	int tamanho;
	int validadeCpf;
	int validadeData;
	int validadeSexo;
	int validadeMatricula;

	op = 1;
	while(op == 1){
		printf("\nInsira o CPF do professor que deseja atualizar:\n");
	    fgets(cpfAtt, 20, stdin);
		cpfAtt[strcspn(cpfAtt, "\n")] = 0;

	    for(i = 0; i < PRcad; i++){
			flag = 0;
	        if(strcmp(cadastro[i].cpf, cpfAtt) == 0){
				flag = 1;
				
				printf("\nInsira os novos dados do(a) professor(a) %s:\n", cadastro[i].nome);
				printf("\nNome: ");
				fgets(cadastro[i].nome, 101, stdin);
				cadastro[i].nome[strcspn(cadastro[i].nome, "\n")] = 0;
				
				printf("\nCPF (apenas numeros): ");
				fgets(cadastro[i].cpf, 20, stdin);
				cadastro[i].cpf[strcspn(cadastro[i].cpf, "\n")] = 0;
				validadeCpf = validaCpf(cadastro[i].cpf);
			
				while (validadeCpf == -1) {
					fflush(stdin);
					printf("\nCPF invalido! Tente novamente: ");
					fgets(cadastro[i].cpf, 20, stdin);
					cadastro[i].cpf[strcspn(cadastro[i].cpf, "\n")] = 0;
					validadeCpf = validaCpf(cadastro[i].cpf);
				}
				/*o laço while acima impede que o programa continue com CPF inválido.
				  É preciso fornecer um CPF válido para dar continuidade*/
			
				fflush(stdin);
				printf("\nSexo: ");
				fgets(cadastro[i].sexo, 20, stdin);
				// getchar();
				// cadastro[i].sexo[strcspn(cadastro[i].sexo, "\n")] = 0;
				tamanho = strlen(cadastro[i].sexo);
				if (cadastro[i].sexo[tamanho - 1] == '\n') 
				{
					cadastro[i].sexo[tamanho - 1] = '\0';
				}
				validadeSexo = validaSexo(cadastro[i].sexo);
			
				while (validadeSexo == -1) {
					fflush(stdin);
					printf("\n Genero invalido! Tente novamente: ");
					fgets(cadastro[i].sexo, 20, stdin);
					tamanho = strlen(cadastro[i].sexo);
					
					if (cadastro[i].sexo[tamanho - 1] == '\n')
					{
						cadastro[i].sexo[tamanho - 1] = '\0';
					}
			  
					validadeSexo = validaSexo(cadastro[i].sexo);
				}
			
				printf("\nData de nascimento [dd/mm/aaaa]: ");
				fgets(cadastro[i].data, 12, stdin);
				cadastro[i].data[strcspn(cadastro[i].data, "\n")] = 0;
				char copia[12];
			
				for(int count = 0; cadastro[i].data[count] != '\0'; count++)
				  copia[count] = cadastro[i].data[count];
			
				validadeData = validarNascimento(copia);
				
				if (validadeData == -1)
				{
					fflush(stdin);
					for (int count = 0; count < 12; count++)
					{
						cadastro[i].data[count] = '\0';
						copia[count] = cadastro[i].data[count];
					}
				}
				
				while(validadeData == -1)
				{
					fflush(stdin);
					printf("\nData ou formato invalido! Tente novamente: ");
					fgets(cadastro[i].data, 12, stdin);
					cadastro[i].data[strcspn(cadastro[i].data, "\n")] = 0;
					
					for(int count = 0; cadastro[i].data[count] != '\0'; count++)
						copia[count] = cadastro[i].data[count];
					
					validadeData = validarNascimento(copia);
					if (validadeData == -1)
					{
						fflush(stdin);
						for (int count = 0; count < 12; count++)
						{
							cadastro[i].data[count] = '\0';
							copia[count] = cadastro[i].data[count];
						}
					}
				}
				
				printf("\nCadastro atualizado com sucesso\n");
				break;
			}
		}
				
		if(flag == 0){
			printf("\nO CPF informado nao esta registrado no sistema.\n");
			break;
		}

		op = -1;
		while(op != 1 && op != 0){
			printf("\nDeseja atualizar outro cadastro?\n[1] Sim\n[0] Nao\n");
			scanf("%d", &op);
			getchar();
		}
	}
	
	return PRcad;
}

int matriculaProfessor ( ){
	static int matriculaProfessor = 2022000;
	matriculaProfessor++;
	return matriculaProfessor;
}