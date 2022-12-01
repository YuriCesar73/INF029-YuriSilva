#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "YuriSilva20221160025.h"

typedef struct {

int *vetorPrincipal; // Ponteiro
int tamanho; // Vetor de inteiros. Guarda o tamanho de cada estrutura auxiliar;
int posicaoAtual;
} Estrutura; //Tipo da estrutura criada

Estrutura Struct [TAM];

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{	
	posicao = posicao - 1; //Para o usuário, o indice começa do 1, por isso subtraio uma unidade.
	
	
    int retorno = 0;

	// se posição é um valor válido {entre 1 e 10}
	if (posicao < 0 || posicao > 9)
	{
    	retorno = POSICAO_INVALIDA;
		return retorno;
	}
	
    // a posicao pode já existir estrutura auxiliar
	if (Struct[posicao].vetorPrincipal != NULL){
    	retorno = JA_TEM_ESTRUTURA_AUXILIAR;
		return retorno;
		}
	
    // o tamanho ser muito grande
	
    	//retorno = SEM_ESPACO_DE_MEMORIA;
		
    // o tamanho nao pode ser menor que 1
	if (tamanho < 1) 
	{
    	retorno = TAMANHO_INVALIDO;
		return retorno;
	}
    // deu tudo certo, crie
	Struct[posicao].vetorPrincipal = (int *) malloc (tamanho * sizeof (int));
	Struct[posicao].tamanho = tamanho;

	if (!Struct[posicao].vetorPrincipal) {
		retorno = SEM_ESPACO_DE_MEMORIA;
		return retorno;
	}

	retorno = SUCESSO;
    //retorno = SUCESSO;
	
    return retorno;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Retorno (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
    int retorno = 0;
    int existeEstruturaAuxiliar = 0;
    int temEspaco = 0;
    int posicao_invalida = 0;
	
	posicao = posicao - 1;
	
    if (posicao < 0 || posicao > 9){
        retorno = POSICAO_INVALIDA;
		return retorno;
		}
    else
    {
        // testar se existe a estrutura auxiliar
        if (Struct[posicao].vetorPrincipal != NULL)
        {
			//Verifica se tem espaço para armazenar o valor
            if (Struct[posicao].posicaoAtual < Struct[posicao].tamanho)
            {
                Struct[posicao].vetorPrincipal[Struct[posicao].posicaoAtual] = valor;
				//printf("Posicao atual: %d\n",Struct[posicao].posicaoAtual);
				Struct[posicao].posicaoAtual =  Struct[posicao].posicaoAtual  + 1;
				//printf("Posicao atual: %d\n",Struct[posicao].posicaoAtual);
                retorno = SUCESSO;
            }
            else
            {
                retorno = SEM_ESPACO;
				return retorno;
            }
        }
        else
        {
            retorno = SEM_ESTRUTURA_AUXILIAR;
			return retorno;
        }
    }

    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
    int retorno = SUCESSO;
	posicao = posicao - 1;

	if (posicao < 0 || posicao > 9) 
	{
		retorno = POSICAO_INVALIDA;
		return retorno;
	}

	if (Struct[posicao].vetorPrincipal == NULL)
	{
		retorno = SEM_ESTRUTURA_AUXILIAR;
		return retorno;
	}

	if (Struct[posicao].posicaoAtual == 0)
	{
		retorno = ESTRUTURA_AUXILIAR_VAZIA;
		return retorno;
	}

	Struct[posicao].posicaoAtual = Struct[posicao].posicaoAtual - 1;

    return retorno;
	
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
    int retorno = SUCESSO;
	int i, j;
	int contador = 0;

	posicao = posicao - 1;

	if (Struct[posicao].vetorPrincipal == NULL)
	{
		retorno = SEM_ESTRUTURA_AUXILIAR;
		return retorno;
	}

	for (i = 0; i < Struct[posicao].posicaoAtual; i++)
	{
		if (Struct[posicao].vetorPrincipal[i] == valor)
		{
			for (j = i; j < Struct[posicao].posicaoAtual;j++)
			{
				Struct[posicao].vetorPrincipal[j] = Struct[posicao].vetorPrincipal[j+1];
			}
			contador++;
			break;
		}
	}

	if (contador == 0)
	{
		retorno = NUMERO_INEXISTENTE;
		return retorno;
	}
	else
	{
		Struct[posicao].posicaoAtual = Struct[posicao].posicaoAtual - 1;
	}
	
	return retorno;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    int retorno = 0;
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
        retorno = SUCESSO;

    return retorno;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{

    int retorno = 0;
	int i;

	posicao = posicao - 1;
	if (posicao < 0 || posicao > 9)
	{
		retorno = POSICAO_INVALIDA;
		return retorno;
	}

	if (Struct[posicao].vetorPrincipal == NULL)
	{
		retorno = SEM_ESTRUTURA_AUXILIAR;
		return retorno;
	}

	if (Struct[posicao].posicaoAtual == 0)
	{
		retorno = ESTRUTURA_AUXILIAR_VAZIA;
		return retorno;
	}

	for (i = 0; i < Struct[posicao].posicaoAtual; i++)
	{
		vetorAux[i] = Struct[posicao].vetorPrincipal[i];
	}

	retorno = SUCESSO;
	
    return retorno;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{

    int retorno = SUCESSO;
	int i;


	posicao = posicao - 1;

	if (posicao < 0 || posicao > 9)
	{
		retorno = POSICAO_INVALIDA;
		return retorno;
	}

	if (Struct[posicao].vetorPrincipal == NULL)
	{
		retorno = SEM_ESTRUTURA_AUXILIAR;
		return retorno;
	}

	if (Struct[posicao].posicaoAtual == 0)
	{
		retorno = ESTRUTURA_AUXILIAR_VAZIA;
		return retorno;
	}

	for (i = 0; i < Struct[posicao].posicaoAtual; i++)
	{
		vetorAux[i] = Struct[posicao].vetorPrincipal[i];
	}

	OrdenarValores(vetorAux, Struct[posicao].posicaoAtual);
    
    return retorno;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{

    int retorno = SUCESSO;
	int i, j, k = 0;

	for (i = 0; i < TAM ; i++)
	{
		if (Struct[i].vetorPrincipal != NULL && Struct[i].posicaoAtual != 0)
		{
			for (j = 0; j < Struct[i].posicaoAtual; j++)
			{
				vetorAux[k] = Struct[i].vetorPrincipal[j];
				k++;
			}
		}
	}

	if (k == 0)
	{
		retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
		return retorno;
	}

    return retorno;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int retorno = SUCESSO;
	int i, j, k = 0;

	for (i = 0; i < TAM; i++)
	{
		if (Struct[i].vetorPrincipal != NULL  && Struct[i].posicaoAtual != 0)
		{
			for (j = 0; j <Struct[i].posicaoAtual; j++)
			{
				vetorAux[k] = Struct[i].vetorPrincipal[j];
				k=k+1;
			}
		}
	}

	if (k == 0)
	{
		retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
		return retorno;
	}

	OrdenarValores(vetorAux, k);

    return retorno;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{

    int retorno = SUCESSO;

	posicao = posicao - 1;

	if (posicao < 0 || posicao > 9)
	{
		retorno = POSICAO_INVALIDA;
		return retorno;
	}

	if (Struct[posicao].vetorPrincipal == NULL)
	{
		retorno = SEM_ESTRUTURA_AUXILIAR;
		return retorno;
	}

	int tamanhoFinal = novoTamanho + Struct[posicao].posicaoAtual;

	if (tamanhoFinal < 1)
	{
		retorno = NOVO_TAMANHO_INVALIDO;
		return retorno;
	}

	Struct[posicao].vetorPrincipal = (int*) realloc (Struct[posicao].vetorPrincipal,tamanhoFinal*sizeof(int));

	if (!Struct[posicao].vetorPrincipal)
	{
		retorno = SEM_ESPACO_DE_MEMORIA;
		return retorno;
	}

	else {
		Struct[posicao].tamanho = tamanhoFinal;
		if (Struct[posicao].tamanho < Struct[posicao].posicaoAtual)
		{
			Struct[posicao].posicaoAtual = Struct[posicao].tamanho;
		}
	}

	return SUCESSO;
	
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{

    int retorno = 0;

	posicao = posicao - 1;

	if (posicao < 0 || posicao > 9)
	{
		retorno = POSICAO_INVALIDA;
		return retorno;
	}

	if (Struct[posicao].vetorPrincipal == NULL)
	{
		retorno = SEM_ESTRUTURA_AUXILIAR;
		return retorno;
	}

	if (Struct[posicao].posicaoAtual == 0)
	{
		retorno = ESTRUTURA_AUXILIAR_VAZIA;
		return retorno;
	}

	retorno = Struct[posicao].posicaoAtual;


    return retorno;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{

    return NULL;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/

void inicializar()
{
	int i;
	for (i = 0; i < TAM; i++) Struct[i].vetorPrincipal = NULL;

	for (i = 0; i < TAM; i++) Struct[i].posicaoAtual = 0;

	
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar()
{
}


void OrdenarValores (int vetor[], int tam){
	
	int i, j, min, aux;
	
	for (i = 0; i < (tam-1); i++) 
	{
	 min = i;
	 for (j = (i+1); j < tam; j++) {
	   if(vetor[j] < vetor[min]) 
		 min = j;
	 }
	 if (i != min) {
	   aux = vetor[i];
	   vetor[i] = vetor[min];
	   vetor[min] = aux;
	 }
	}
}