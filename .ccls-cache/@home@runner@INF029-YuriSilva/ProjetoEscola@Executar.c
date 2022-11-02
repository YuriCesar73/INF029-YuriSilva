#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "Aluno.h"
#include "Professor.h"
#include "Disciplina.h"


#define QTD_Alunos 100
#define QTD_Professores 100
#define anoAtual 2022
void buscaPessoas(Alunos cadAl[], Professores cadPr[]);
void aniversarioMes (Alunos cadAl[], Professores cadPr[]);

int main() {
    Alunos cadastroAl[QTD_Alunos];
    Professores cadastroPr[QTD_Professores];
	Disciplinas disciCadastradas[10];
    
    int opA = 1;
    int opB, opC;
    
    while (opA > 0){
        do {
			printf("\n\tMENU");
			printf("\n[1] Alunos");
            printf("\n[2] Professores");
            printf("\n[3] Disciplinas");
            printf("\n[4] Buscar pessoas");
            printf("\n[5] Aniversarientes do mes");
            printf("\n[0] Sair\n");
			scanf("%d", &opA);
                if(opA > 5 || opA < 0){
                    do{
                        printf("Valor inválido!! Digite novamente...\n: ");
                        scanf("%d", &opA);
                    } while(opA > 5 || opA < 0);
                }
	    } while (opA < 0 || opA > 5);
        
        switch (opA) {
            case 1:
                opB = 1;
    		      	while (opB != 0) {
    			        do {
                            printf("\n[1] Cadastrar alunos");
                            printf("\n[2] Listar alunos");
                            printf("\n[0] Voltar\n");
    			            scanf("%d", &opB);
    			        } while (opB < 0 || opB > 2);
                        
    		            switch (opB) {
    			        case 1:
    						opC = 1;
    						while (opC != 0) {
    				            do {
                                    printf("\n[1] Cadastrar novo");
                                    printf("\n[2] Excluir cadastro");
                                    printf("\n[3] Atualizar cadastro");
    				              	printf("\n[0] Voltar\n");
    				              	scanf("%d", &opC);
    								getchar(); 
    				            } while (opC < 0 || opC > 3);
    			
    							switch (opC) {
    					            case 1:
    									ALcad = cadastroAlunos(cadastroAl);
    									break;								
    								case 2:
    									ALcad = excluiAlunos(cadastroAl);
    									break;								
    								case 3:
    									ALcad = atualizaAlunos(cadastroAl);
    									break;								
    								case 0:
    									break;
    							}
    						}
    					break;
    							
    					case 2:
    						opC = 1;
    						while (opC != 0) {
    						    do {
                                    printf("\n[1] Todos");
                                    printf("\n[2] Por sexo");
                                    printf("\n[3] Por nome");
                                    printf("\n[4] Por data de nascimento");
                                    printf("\n[5] Matriculados em menos de 3 disciplinas");
                                    printf("\n[0] Voltar\n");                               
    								scanf("%d", &opC);
    							} while (opC < 0 || opC > 5);
    						
        						switch (opC) {
                                    case 1:
                                    	listaAlunos(cadastroAl);
                                      break;
        						
                                    case 2:
                                    	ordenaSexoAlun(cadastroAl);
                                        break;
        						
                                    case 3:
                                    	ordenaNomeAlunos(cadastroAl);
                                        break;
        						
                                    case 4:
                                        ordenaDataAlunos(cadastroAl);
                                        break;
        						
                                    case 5:
                                        // matriculadosMenosDe3();
                                        break;
        						
                                    case 0:
                                        break;
                                }
    		          		}
                            
    	        	}
    			}
    	
    	    	break;
    	
    		    case 2:
    		      	opB = 1;
    		      	while (opB != 0) {
    			        do {
    			        	printf("\n[1] Cadastrar professores");
                            printf("\n[2] Listar professores");
                            printf("\n[0] Voltar\n");
    			        	scanf("%d", &opB);
    			        	getchar();
    			        } while (opB != 0 && opB != 1 && opB != 2);
    		
    			        switch (opB) {
    				        case 1:
    							opC = 1;
    							while (opC != 0) {
    								do {
    									printf("\n[1] Cadastrar novo");
                                        printf("\n[2] Excluir cadastro");
                                        printf("\n[3] Atualizar cadastro");
                                        printf("\n[0] Voltar\n");
    									scanf("%d", &opC);
    									getchar();
    								} while (opC < 0 || opC > 3);
    			
    								switch (opC) {
    									case 1:
    						        		PRcad = cadastroProfessores(cadastroPr);
    										break;
    									
    									case 2:
    										PRcad = excluiProfessores(cadastroPr);
    										break;
    									
    									case 3:
    										PRcad = atualizaProfessores(cadastroPr);
    										break;
    									
    									case 0:
    										break;
    								}
    							}
    					
    							break;
    		
    				        case 2:
    				    		opC = 1;
    				        	while (opC != 0) {
    					            do {
    					              	printf("\n[1] Todos");
                                        printf("\n[2] Por sexo");
                                        printf("\n[3] Por nome");
                                        printf("\n[4] Por data de nascimento");
                                        printf("\n[0] Voltar\n");
    					              	scanf("%d", &opC);
    					            } while (opC < 0 || opC > 4);
    	
    								switch (opC) {
    									case 1:
    							            listaProfessores(cadastroPr);
    							            break;
    						
    						            case 2:
    						        		ordenaSexoProf(cadastroPr);
    						            	break;
    						
    						            case 3:
    						            	ordenaNomeProf(cadastroPr);
    						            	break;
    						
    						            case 4:
    						            	ordenaDataProf(cadastroPr);
    						            	break;
    						
    						            case 0:
    						            	break;
    				            	}
    							}
    						}
    					}
    				    break;
    	
    		    case 3:
    			    opB = 1;
    			    while (opB != 0) {
    			        do {
    					  	printf("\n[1] Cadastrar disciplinas");
                            printf("\n[2] Listar disciplinas");
                            printf("\n[0] Voltar\n");
    					  	scanf("%d", &opB);
    		            getchar();
    			        } while (opB != 0 && opB != 1 && opB != 2);
    		
    			        switch (opB) {
    				        case 1:
    				        	cadastroDisciplina(disciCadastradas);
    				        	break;
    		
    				        case 2:
    				        	opC = 1;
    				        	while (opC != 0) {
    					            do {
    					              	printf("\n[1] Apenas dados");
                                        printf("\n[2] Dados e alunos");
                                        printf("\n[3] Mais de 40 vagas");
                                        printf("\n[0] Voltar\n");
    					              	scanf("%d", &opC);
    					            } while (opC != 0 && opC != 1 && opC != 2);
    					
    					            switch (opC) {
    						            case 1:
    						            	// ordenaDados();
    						            	break;
    						
    						            case 2:
    						            	// ordenaDadosAlunos();
    						            	break;
    						
    						            case 3:
    						            	// maisde40();
    						            	break;
    						
    						            case 0:
    						            	break;
    				            	}
    				          	}
    			    	}
    	    		}
    	
    	    		break;
    		
    		    case 4:
    				buscaPessoas(cadastroAl, cadastroPr);
    				break;
    		
    		    case 5:
    				aniversarioMes (cadastroAl, cadastroPr);
    				break;
    		
    		    case 0:
    				return 0;
		}     
    }
    // 
    return 0;
}


void buscaPessoas(Alunos cadAl[], Professores cadPr[]){
	char busca[101];
	char auxNome[101];
	char auxBusca[101];
	int i, j, n;
	int op = 1;
	while(op == 1){	
		do{
			printf("\nDigite ao menos 3 letras para buscar uma pessoa:\n> ");
			getchar();
			scanf("%s", busca);
			getchar();
			if(strlen(busca) < 3){
				printf("\nTexto insuficiente.");
			}
		} while (strlen(busca) < 3);
	
		
		for(i = 0; i < strlen(busca); i++){
			auxBusca[i] = tolower(busca[i]);
		}
		auxBusca[i] = '\0';
	
			
		printf("\n\tPessoas encontradas:\n\n");
		for (j = 0; j < ALcad + PRcad; j++){
			
			for(i = 0; i < strlen(cadAl[j].nome); i++){
				auxNome[i] = tolower(cadAl[j].nome[i]);
			}
			auxNome[i] = '\0';

			if (strstr(auxNome, auxBusca) != NULL){
				printf("Nome........: %s\n", cadAl[j].nome);
				printf("Matricula...: %ld\n", cadAl[j].matricula);
				printf("CPF.........: %s\n", cadAl[j].cpf);
				printf("Sexo........: %c\n", cadAl[j].sexo[0]);
				printf("Nascimento..: %s\n", cadAl[j].data);
				printf("\n");
			}

			for(i = 0; i < strlen(cadPr[j].nome); i++){
				auxNome[i] = tolower(cadPr[j].nome[i]);
			}
			auxNome[i] = '\0';
			
			if (strstr(auxNome, auxBusca) != NULL){
				printf("Nome........: %s\n", cadPr[j].nome);
				printf("Matricula...: %ld\n", cadPr[j].matricula);
				printf("CPF.........: %s\n", cadPr[j].cpf);
				printf("Sexo........: %c\n", cadPr[j].sexo[0]);
				printf("Nascimento..: %s\n", cadPr[j].data);
				printf("\n");
			}
		}

		op = -1;
		while(op != 1 && op != 0){
			printf("\nBuscar novamente?\n[1] Sim\n[0] Nao\n");
			scanf("%d", &op);
		}
	}
}

void aniversarioMes (Alunos cadAl[], Professores cadPr[])
{
	char mes [3];
	int tamanho, i, j, countUm, countDois, op;
	j = 0;
	op = 1;

	while (op == 1){
	 	countUm = countDois = 0;
		do {
			fflush(stdin);
			printf("Digite o mês que você deseja saber os aniversariantes: \n");
			getchar();
			scanf("%s",mes);
			mes[2] = '\0';
				if(strlen(mes) != 2){
				printf("\nDado errado. Insira dois digitos.\n");
			}
		} while (strlen(mes) != 2);
	
	printf("\nAlunos aniversariantes do mês escolhido: \n");	
	for (i = 0; i < ALcad; i++) {
		if (mes[j] == cadAl[i].data [3])
		{
			if (mes[j+1] == cadAl[i].data [4])
			{
				printf("Nome...........: %s\n",cadAl[i].nome);
				printf("Matricula......: %ld\n",cadAl[i].matricula);
				printf("CPF............: %s\n",cadAl[i].cpf);
				printf("Sexo...........: %s\n",cadAl[i].sexo);
				printf("Nascimento.....: %s\n",cadAl[i].data);
				countUm++;
			}
			printf("\n");
		}
	}

	if (countUm==0) printf("Não há alunos que fazem aniversário no mês escolhido\n");

	printf("\nProfessores aniversariantes do mês escolhido: \n");	
	for (i = 0; i < PRcad; i++) {
		if (mes[j] == cadPr[i].data [3])
		{
			if (mes[j+1] == cadPr[i].data [4])
			{
				printf("Nome...........: %s\n",cadPr[i].nome);
				printf("Matricula......: %ld\n",cadPr[i].matricula);
				printf("CPF............: %s\n",cadPr[i].cpf);
				printf("Sexo...........: %s\n",cadPr[i].sexo);
				printf("Nascimento.....: %s\n",cadPr[i].data);
				countDois++;
			}
			printf("\n");
		}

	}

		if (countDois==0) printf("Não há professores que fazem aniversário no mês escolhido\n");


		op = -1;
		while(op != 1 && op != 0){
			printf("\nPesquisar novamente?\n[1] Sim\n[0] Nao\n");
			scanf("%d", &op);
		};
	
	}

}