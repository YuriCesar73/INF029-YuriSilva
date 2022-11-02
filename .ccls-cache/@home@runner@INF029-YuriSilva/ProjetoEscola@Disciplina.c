#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "Aluno.h"
#include "Professor.h"
#include "Disciplina.h"
#include "Valida.h"
#define anoAtual 2022

static int DScad = 0;

Disciplinas cadastroDisciplina(Disciplinas cadastro[])
{
    int op = 1;
    int validadeNome;
    int validadeCodigo;
    int validadeSemestre;
    int validadeProfessor;
    
    while(op == 1)
    {
        fflush(stdin);
    
        printf("\nNome: ");
        fgets(cadastro[DScad].nome, 101, stdin);
        cadastro[DScad].nome[strcspn(cadastro[DScad].nome, "\n")] = 0;
        
        //validação do nome
        
        printf("\nCodigo (3 letras maiusculas e 3 numeros): ");
        fgets(cadastro[DScad].codigo, 8, stdin);
        cadastro[DScad].codigo[strcspn(cadastro[DScad].codigo, "\n")] = 0;
        
        //validação do código
        
        printf("\nSemestre (formato ANO.SEMESTRE <AAAA.S>): ");
        fgets(cadastro[DScad].semestre, 8, stdin);
        cadastro[DScad].semestre[strcspn(cadastro[DScad].semestre, "\n")] = 0;
        
        //validação do semestre
        
        printf("\nProfessor: ");
        fgets(cadastro[DScad].professor, 101, stdin);
        cadastro[DScad].professor[strcspn(cadastro[DScad].professor, "\n")] = 0;
        
        //validação do professor
		
        printf("\nDeseja realizar outro cadastro?");
		printf("\n[1] Sim");
		printf("\n[0] Nao\n");
	    scanf("%d", &op);
	    getchar();
	
	    while (op != 1 && op != 0) 
	    {
        	printf("\nOpcao invalida! Tente novamente: ");
        	scanf("%d", &op);
        	getchar();
	    }
	    
	    if (op == 1) 
	    {
	    	DScad++;
	    }
    }
    
    DScad++;
}

