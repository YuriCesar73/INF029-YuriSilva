// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Yuri Cesar Lima Silva
//  email: ycesar4273@gmail.com
//  Matrícula: 20221160025
//  Semestre: 2022.2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include "YuriSilva20221160025.h" // Substitua pelo seu arquivo de header renomeado
#include <stdlib.h>
#include <string.h>
/*
## função utilizada para testes  ##
 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##
 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}



DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  	char sDia[3];
	char sMes[3];
	char sAno[5];
	int i, tamanho;

	//Adição minha esta parte do código
	tamanho = strlen (data);

	for (i = 0; i < tamanho; i++){
		if (data[i] >= 58 || data[i] <= 46){
			dq.valido = 0;
			return dq;
		}
	}

	
	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }  
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
		
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

  dq.valido = 1;
  return dq;
}
/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[])
{
	int datavalida = 1;
	int anoBisexto;

  //quebrar a string data em strings sDia, sMes, sAno

	DataQuebrada dataQuebrada = quebraData(data);

	if (dataQuebrada.valido == 0) 
	{
		return 0;
	}
	if (dataQuebrada.iMes > 12 || dataQuebrada.iMes < 1){
		datavalida = 0; 
	}

	//Verifica os meses com 31 dias
	if (dataQuebrada.iMes == 1 || dataQuebrada.iMes == 3 ||dataQuebrada.iMes == 5 ||dataQuebrada.iMes == 7 ||dataQuebrada.iMes == 8 ||dataQuebrada.iMes == 10 ||dataQuebrada.iMes == 11 || dataQuebrada.iMes == 12) {

		if (dataQuebrada.iDia > 31 && dataQuebrada.iDia > 1) 
		{
			datavalida = 0;
			}

	}
		
	//Verifica os meses com 30 dias
	if (dataQuebrada.iMes == 4 ||dataQuebrada.iMes == 6 ||dataQuebrada.iMes == 9 ||dataQuebrada.iMes == 11){

		if (dataQuebrada.iDia <= 30 && dataQuebrada.iDia >= 1) datavalida = 1;

		else datavalida = 0;
	}
	
	//Verifica se o ano é bisexto ou não
	
		if (dataQuebrada.iAno > 100){

			if (dataQuebrada.iAno % 4 == 0 || (dataQuebrada.iAno % 100) == 0 &&  (dataQuebrada.iAno % 400) == 0) anoBisexto = 1;

			else anoBisexto = 0;
		
		}
	
		if (dataQuebrada.iAno < 100){
			dataQuebrada.iAno = dataQuebrada.iAno + 2000;

			if (dataQuebrada.iAno % 4 == 0 || (dataQuebrada.iAno % 100) == 0 &&  (dataQuebrada.iAno % 400) == 0) anoBisexto = 1;

			else anoBisexto = 0;
		
		}

	//Verifica o mes de fevereiro
	if (dataQuebrada.iMes == 2)
	{
		if (anoBisexto == 1){
			if (dataQuebrada.iDia < 1 || dataQuebrada.iDia > 29) datavalida = 0;
		}

		else if (anoBisexto == 0) 
		{
			if (dataQuebrada.iDia < 1 || dataQuebrada.iDia > 28) datavalida = 0;
		}
	}
	

  if (datavalida == 1) {
	return 1;	  
  }
	else return 0;
}



/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[])
{

    //calcule os dados e armazene nas três variáveis a seguir
    DiasMesesAnos dma;
	DataQuebrada primeiraData;
	DataQuebrada segundaData;
	int iDia, iMes, iAno, dias, i;

	 dias = i =   0;
	

	primeiraData = quebraData (datainicial);
	segundaData = quebraData (datafinal);
	
    if (q1(datainicial) == 0){
      dma.retorno = 2;
      return dma;
    }else if (q1(datafinal) == 0){
      dma.retorno = 3;
      return dma;
    }else if (primeiraData.iAno > segundaData.iAno){
		dma.retorno = 4;
		return dma;
	}else if (primeiraData.iMes > segundaData.iMes){
		dma.retorno = 4;
		return dma;
	}
	else if (primeiraData.iDia > segundaData.iDia){
		dma.retorno = 4;
		return dma;
	}

	/* ERRO: NÃO CONSEGUE SAIR DO LOOP
	
	iDia = segundaData.iDia - primeiraData.iDia;
	iMes = segundaData.iMes - primeiraData.iMes;
	iAno = segundaData.iAno - primeiraData.iAno;

	
	
	if (primeiraData.iDia == segundaData.iDia && primeiraData.iMes == segundaData.iMes && primeiraData.iAno == segundaData.iAno)
	{
		dma.qtdDias = 0;
		dma.qtdMeses = 0;
		dma.qtdAnos = 0;
	}

	else 
	{
		dma.qtdDias = 0;
		dma.qtdMeses = 0;
		dma.qtdAnos = 0;
		
		while (primeiraData.iAno != segundaData.iAno || primeiraData.iMes != segundaData.iMes || primeiraData.iDia != segundaData.iDia)
		{
			if (dma.qtdMeses > 12) 
			{
				dma.qtdMeses = 1;
				dias++;
			}

			if (primeiraData.iMes == 1 || primeiraData.iMes == 3 || primeiraData.iMes == 5 || primeiraData.iMes == 7 || primeiraData.iMes == 8 || primeiraData.iMes == 10 || primeiraData.iMes == 12)
			{
				i++;
				dias++;
				dma.qtdDias = i;
				primeiraData.iDia = primeiraData.iDia + 1;
					if (dma.qtdDias == 32)
					{
						dma.qtdMeses = dma.qtdMeses + 1;
						dma.qtdDias = 0;
						i = 0;
					}

					if (primeiraData.iDia > 31)
					{
						primeiraData.iDia = 1;
						primeiraData.iMes = primeiraData.iMes + 1;
					}
			}

			if (primeiraData.iMes == 4 || primeiraData.iMes == 6 || primeiraData.iMes == 9 || primeiraData.iMes == 11)
			{
				i++;
				dias++;
				dma.qtdDias = i;
				primeiraData.iDia = primeiraData.iDia + 1;
					if (dma.qtdDias == 31)
					{
						dma.qtdMeses = dma.qtdMeses + 1;
						dma.qtdDias = 0;
						i = 0;
					}

					if (primeiraData.iDia > 30)
					{
						primeiraData.iDia = 1;
						primeiraData.iMes = primeiraData.iMes + 1;
					}
			}
			if (primeiraData.iMes == 2)
			{
				i++;
				dias++;
				dma.qtdDias = i;
				primeiraData.iDia = primeiraData.iDia + 1;
					if (dma.qtdDias == 29){
						dma.qtdDias = 0;
						dma.qtdMeses = dma.qtdMeses + 1;
						i = 0;
					}

					if (primeiraData.iDia > 28){
						primeiraData.iDia = 1;
						primeiraData.iMes = primeiraData.iMes + 1;
					}
			}

			if (dias == 365)
			{
				//printf("Ele ta aqui\n");
				printf("%d / %d / %d \n",primeiraData.iDia, primeiraData.iMes, primeiraData.iAno);
				dma.qtdAnos = dma.qtdAnos + 1;
				dma.qtdDias = 0;
				dma.qtdMeses = 0;
				dias = 0;
			}

			if (primeiraData.iMes > 12)
			{
				primeiraData.iMes = 1;
				primeiraData.iAno = primeiraData.iAno + 1;
			}
		}
	}
*/

	
     // dma.retorno = 1;
      return dma;
      
    
    
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
    int qtdOcorrencias = 0;
	int i;
	char aux [250];
	

	for (i = 0; texto[i] != '\0'; i++) aux[i] = texto[i];
	
	//Considera a diferença entre maiusculas e minusculas
	if (isCaseSensitive == 1)
	{
	
		for  (i = 0; aux[i] != '\0'; i++)
			{
				if (aux[i] == c) qtdOcorrencias++;
			}
	
	}
	//Não considera a diferença entre maiúsculas e minúsculas
	if (isCaseSensitive != 1) 
	{
		for (i = 0; aux[i] != '\0'; i++)
		{
			if (aux[i] >= 65 && texto[i] <= 90)
			{
				aux[i] = aux [i] + 32;	
			}
		}	

		if (c >= 65 && c <= 90) c = c + 32;
		
		for  (i = 0; aux[i] != '\0'; i++)
		{
			if (aux[i] == c) qtdOcorrencias++;
		}

	}
	
    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;
 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
    int qtdOcorrencias = 0;
	int tamanhoTexto, contadorTexto, contadorBusca, tamanhoBusca;
	int i, j, k, flag;
	char strTextoAuxiliar[250];

	//função para verificar se a frase e a palavra tem acento e corrigir. Está lá no fundo do código
	corrigeAcento (strTexto);
	corrigeAcento (strBusca);
	
	tamanhoTexto = strlen (strTexto);
	tamanhoBusca = strlen (strBusca);
	
	contadorBusca = contadorTexto = i = j = flag = k = 0;
	
	while (contadorTexto < tamanhoTexto)
	{
		if (strTexto[i] == strBusca[j])
		{
			flag++;
			i++;
			j++;
			contadorTexto++;
		}
		else if (strTexto[i] != strBusca[j])
		{
			flag = 0;
			j = 0;
			i++;
			contadorTexto++;
		}

		if (flag == tamanhoBusca)
		{
			qtdOcorrencias++;
			posicoes[k] = i - (tamanhoBusca - 1);
			k++;
			posicoes[k] = i;
			k++;
			flag = 0;
		}

		if (tamanhoBusca == j) j = 0;
	}
	
    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{
	int i, divisor, multiplicador, numero, n;
	
	divisor = 10;
	i = 1;
	numero = num;
	multiplicador = 1;
	n = 0;

	if (num < 10) return num;

	// Verifica quantas vezes o numero vai ter que ser dividido
	while ( (numero / divisor) != 0 || (numero % divisor) >= num)
	{
		numero = numero / divisor;
		i++;
		multiplicador = multiplicador * 10;
	}

	numero = num;

	// Faz as divisões sucessivas para poder pegar cada número individual
	for ( ; i > 0; i--)
	{
		n = n + ((numero % divisor) * multiplicador);
		numero = numero / divisor;
		multiplicador = multiplicador / 10;	
	}

	//printf("\n%d\n",n);
	num = n;
    return num;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
    int qtdOcorrencias;
	qtdOcorrencias = 0;

	int k, i, j, countNatural, countK, numero, divisor, contador, flag;
	int A[25];
	int B[25];
	int aux [25];
	
	divisor = 10;
	i = countNatural = countK  = contador = flag = 0;
	
	numero = numerobase;
	

	if (numerobase == 0)
	{ 
		aux [0] = 0;
		countNatural++;
	}

	else if (numerobase != 0)
	{
		while ( (numerobase / divisor) != 0 || (numerobase % divisor) >= numero || numerobase > 0)
			{
				aux[i] = numerobase % divisor;
				numerobase = numerobase/divisor;
				i++;
				countNatural++;
			}
	}

	i = 0;
	
	for (j = countNatural -1; j >= 0 ; j--)
	{
		A[i] = aux[j];
		i++;
	}

	i = 0;
	
	if (numerobusca == 0) 
	{
		B [0] = 0;
		countK++;
	}
	else if (numerobusca!= 0)
	{
		while ( (k / divisor) != 0 || (k % divisor) >= numero || numerobusca > 0)
		{
			aux[i] = numerobusca % divisor;
			numerobusca = numerobusca/divisor;
			i++;
			countK++;
		}	
	}
	
	i = 0;
	
	for (j = countK - 1; j >= 0 ; j--)
	{
		B[i] = aux[j];
		i++;
	}
	
	i = j = 0;
	
	while (contador < countNatural)
	{
		if (A[i] == B[j])
		{
			flag++;
			j++;
			i++;
			contador++;
			
		}
		else if (A[i] != B[j])
		{
			flag = 0;
			j = 0;
			i++;
			contador++;
			
		}
		
		if (flag == countK)
		{
			qtdOcorrencias++;
			flag = 0;
		}

		if (j == countK) j = 0;
	}
	
return qtdOcorrencias;

}


void corrigeAcento (char strTexto[]){

	int i, j;
	int caracterInt[250];
	char auxiliar [250];
	int tamanho;
	
	for (i = 0, j = 0; strTexto[i] != '\0'; i++){
       if (strTexto[i] != -61){ 
           caracterInt[j] = strTexto[i];
           j++;
       }
   }
   
   for (i = 0; i < j; i++) {
        auxiliar[i] = caracterInt [i];   
   }
    auxiliar[i] = '\0';
  
    for (j = 0; j < i; j++) strTexto[j] = auxiliar[j];
	strTexto[j] =  '\0';
   
	
}