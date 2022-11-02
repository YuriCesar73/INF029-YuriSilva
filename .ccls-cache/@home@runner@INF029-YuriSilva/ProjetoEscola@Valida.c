#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "Aluno.h"
#include "Professor.h"
#include "Valida.h"
#define anoAtual 2022

// static int ALcad = 0;
// static int PRcad = 0;

int validaCpf(char cpf[]) {
	int cpfNum[12];
	int i, j, digiVeri = 0;
	
	if (strlen(cpf) != 11)
	return -1;
	
	for (i = 0; cpf[i] != '\0'; i++) {
	if (cpf[i] < '0' ||
		cpf[i] > '9') // essa condicional garante que o só entram números no cpf
		return -1;
		cpfNum[i] = cpf[i] - 48; // aqui, convertemos o cpf em int pra ficar mais
							 // fácil de trabalhar na validação
	}
	for (i = 0, j = 10; i < 9; i++, j--) {
		digiVeri += j * (cpfNum[i]);
	}
	
	digiVeri %= 11;
	
	if (digiVeri == 1 || digiVeri == 0)
		digiVeri = 0;
	else
		digiVeri = 11 - digiVeri;
	
	if (digiVeri != cpfNum[9])
		return -1;
	else {
		digiVeri = 0;
		
	for (i = 0, j = 11; i < 10; i++, j--) {
		digiVeri += j * (cpfNum[i]);
	}
	
	digiVeri %= 11;
		
	if (digiVeri == 1 || digiVeri == 0)
	  digiVeri = 0;
	else
		digiVeri = 11 - digiVeri;
		
	if (digiVeri != cpfNum[10])
		return -1;
	else
		return 1;
	}
}

int validaSexo(char sexo[]) {
	int i, count;
	char Letras[] = {"MFO"};
	count = 0;

	sexo[0] = toupper(sexo[0]);

	for (i = 0; Letras[i] != '\0'; i++) {
	    if (Letras[i] == sexo[0]) {
	    	count++;
	    	break;
	    }
	}
  	if (count == 1) {
    	return 1;
  	} else {
    	return -1;
  	}
}

int validarNascimento(char dataNasc[]){
    
    char aux[12];
    int data;
    int dia, mes, ano;
    int i, j = 0;
    int erros = 0;
    
    if(dataNasc[2] != '/' || dataNasc[5] != '/')
        return -1;
    
    for(i=0; dataNasc[i] != '\0'; i++)
        aux[i] = dataNasc[i];
    
    // Copiando apenas numeros para o vetor dataNasc
	for(i = 0; aux[i] != '\0'; i++){
		if(aux[i] >= 48 && aux[i] <= 57){
			dataNasc[j] = aux[i];
			j++;
		}
	}
	dataNasc[j] = '\0';
        
    if(j < 8)
        return -1;
        
    // Transformando a data (string) em data (int)
    data = atoi(dataNasc);
    
    ano = data % 10000;
    mes = (data / 10000) % 100;
    dia = data / 1000000;
    
    if(dia > 31)
        erros = -1;
        // printf("\nDia invalido");
    if(mes > 12)
        erros = -1;
        // printf("\nMes invalido");
    if(ano > anoAtual)
        erros = -1;
        // printf("\nAno maior que o ano atual");
    
    int maxDias;
    if(mes == 2){
        if((ano % 400 == 0) || ((ano % 4 == 0) && (ano % 100 != 0))) {
            // Ano Bissexto
            if(mes == 2)
                maxDias = 29;
        }
        else {
            // Ano não bissexto
            if(mes == 2)
                maxDias = 28;
        }
        if(mes == 2 && dia > maxDias)
            erros = -1;
            // printf("Erro. O mes %d teve %d dias neste ano.", mes, maxDias);
    }
    else{
        if(mes == 4 || mes == 6 || mes == 9 || mes == 11)
            maxDias = 30;
        else
            maxDias = 31;
            
        if(dia > maxDias)
            erros = -1; 
            // printf("\nErro. O mes %d possui apenas %d dias", mes, maxDias);
    }

    return erros;
}