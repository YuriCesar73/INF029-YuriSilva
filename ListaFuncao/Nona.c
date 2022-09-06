#include <stdio.h>
#include <string.h>
#define len 100

typedef  struct {

  int dia;
  int mes;
  int ano;
} data;


void cadastrarCliente (char nome [], data nascimento [], char cpf[], char sexo [], int validades []);
int validaSexo (char sexoValida [], int validades []);
void validaNome (char nome [], int validades [], int tamanho);
int validaData (data nascimento [], int validades []);
int validaCpf (char cpf [], int validades []);

int main () {
  
  data nascimento [1];
  char nome [len];
  char cpf [len];
  char sexo [len];

  int validades [4];
  /* Indice para identificação dos dados:
  Indice 0 = Sexo;
  Indice 1 = Nome;
  Indice 2 = Data;
  Indice 3 = Cpf; 

  Se o valor for 0 = Dados validados com sucesso
  Se o valor for -1 = Dados inválidos
*/

  for(int i=0;i<4;i++){
    validades[i]=0;
  }
  
  //Função: Recebe os dados do cliente.
  cadastrarCliente(nome , nascimento ,  cpf , sexo, validades);

  //Saída dos dados


  printf("___________________________\n");

  if (validades[0]==-1){
    printf("Cadastro inválido. Erro na informação do sexo\n");
  }
  if (validades[1]==-1){
    printf("Cadastro inválido. Erro na informação do nome\n");
  }
  if (validades [2]==-1){
    printf("Cadastro inválido. Erro na informação da data de nascimento\n");
  }
  if (validades[3]==-1){
    printf("Cadastro inválido. Erro na informação do CPF\n");
  }

  if (validades[0]==0 && validades[1]==0 && validades[2]==0 && validades[3]==0){
    printf("Cadastro feito com sucesso!!\n");
    printf("Os dados cadastrados foram: \n");
    printf ("Nome: %s\n",nome);
    printf("Data de nascimento: %d/",nascimento[0].dia);
    printf("%d/",nascimento[0].mes);
    printf("%d\n",nascimento[0].ano);
    printf("Cpf: %s\n",cpf);
    printf("Sexo: %s\n",sexo);
  }

  
}

// Função de cadastro do usuário
void cadastrarCliente (char nome [],data nascimento [], char cpf[],char sexo [],int validades []) {

 int tamanho;

  // Recebe Nome
  printf("Digite o seu nome: \n");
    fgets (nome,len,stdin);
    tamanho= strlen (nome); 

		if (nome [tamanho-1]=='\n'){
        nome [tamanho-1]='\0';
      }

  //Função para validar nome
  validaNome (nome, validades, tamanho);
  
  // Recebe Data de Nascimento
  printf("Digite o dia do nascimento: \n");
    scanf("%d",&nascimento[0].dia);
    getchar();
  printf("Digite o mês do nascimento: \n");
    scanf("%d",&nascimento[0].mes);
    getchar();
  printf("Digite o ano do nascimento: \n");
    scanf("%d",&nascimento[0].ano);
    getchar();

  //Função para validar a data
  validaData (nascimento, validades);
  
  // Recebe Cpf
  printf("Digite o seu cpf: \n");
    fgets (cpf,len,stdin);
    tamanho= strlen (cpf); 

  		if (cpf [tamanho-1]=='\n'){
          cpf [tamanho-1]='\0';
        }

  validaCpf(cpf, validades);
  
  // Recebe Sexo
  printf("Digite o seu sexo: \n");
    fgets (sexo,len,stdin);
    tamanho= strlen (sexo); 

  		if (sexo [tamanho-1]=='\n'){
          sexo [tamanho-1]='\0';
        }  

    // Função para validar sexo
    validaSexo (sexo, validades);
  
  }



//Função para validar Sexo
int validaSexo (char sexoValida [], int validades []){

  int i = 0;

  // Comparação da resposta do usuário
  if (sexoValida [i] == 'm' || sexoValida [i] == 'M' || sexoValida [i] == 'F'      || sexoValida [i] == 'f' || sexoValida [i] == 'o' || sexoValida [i] == 'O')   {

    validades[0] = 0;
    return 0;
    
  }
    
  else {
    
    validades[0] = -1;
    return -1;
    }
}

// Função para validar o nome
void validaNome (char nome [], int validades [], int tamanho){

  int count;
  int i;
  count=0;

  //Conta quantos caracteres o nome tem (e apenas o nome)
  for (i=0;i<tamanho-1;i++){

    if (nome[i]!= 32){
      count++;
    }
     
  }

  if (count >20){
    validades [1] = -1;
  }
  else {
    validades [1] = 0;
  }
  
}

// Valida a data de nascimento
int validaData (data nascimento [], int validades []){

int i,a;

//Verifica o ano
  if (nascimento[0].ano > 2022 && nascimento[0].ano < 1900){

    validades [2] = -1;
    return -1;
  
}
  else {

    validades[2] = 0;
}

// Verifica o mes
  if (nascimento[0].mes > 12 || nascimento[0].mes < 1){

    validades [2] = -1;
    return -1;
}

  else {
    validades[2]=0;
  }

// Verifica os meses com 31 dias
if (nascimento[0].mes == 1 ||nascimento[0].mes == 3 ||nascimento[0].mes == 5       ||nascimento[0].mes == 7 ||nascimento[0].mes == 8 ||nascimento[0].mes == 10    ||nascimento[0].mes == 12){
  if (nascimento[0].dia <= 31 && nascimento[0].dia >= 1){
      validades [2] = 0;
  }
  else {
    validades[2] = -1;
    return -1;
  }
    }
  
  // Verifica os dias de fevereiro
  if (nascimento[0].mes == 2){
    for (a=2024;a>nascimento[0].ano;a = a-4){
    }

    // Verifica se o ano eh bissexto
    if (a==nascimento[0].ano){
      if (nascimento[0].dia <=29 && nascimento[0].dia >=1){
        validades [2]=0;
      }
      else{
        validades[2]=-1;
        return -1;
      }
    }

  if (a!=nascimento[0].ano){
    
    if (nascimento[0].dia <=28 && nascimento[0].dia >=1){
      validades [2]=0;
    }
    else {
      validades[2]=-1;
      printf("\n AA2 eh igual a %d\n",a);
      return -1;
    }

    }
  }
  
  
  // Verifica os dias dos meses com 30 dias
  if (nascimento[0].mes== 4 || nascimento[0].mes== 6 ||nascimento[0].mes== 9 ||nascimento[0].mes== 11){
    if (nascimento[0].dia >=1 && nascimento[0].dia <= 30){
      validades [2] =0;
    }
      
    else {
      validades [2] = -1;
      return -1;
    }
    
  }

}



int validaCpf (char cpf [], int validades []){

int cpfInt [11];
int i,j,n,soma;
int digitoVerificador1, digitoVerificador2;

  n=0;

  //Criação de um vetor de inteiro com os numeros do cpf
  for (i=0;cpf[i]!='\0';i++){

    if (cpf[i]==48){
      cpfInt[n]=0;
      n++;
    }
    if (cpf[i]==49){
      cpfInt[n]=1;
      n++;
    }
    if (cpf[i]==50){
      cpfInt[n]=2;
      n++;
    }
    if (cpf[i]==51){
      cpfInt[n]=3;
      n++;
    }
    if (cpf[i]==52){
      cpfInt[n]=4;
      n++;
    }
    if (cpf[i]==53){
      cpfInt[n]=5;
      n++;
    }
    if (cpf[i]==54){
      cpfInt[n]=6;
      n++;
    }
    if (cpf[i]==55){
      cpfInt[n]=7;
      n++;
    }
    if (cpf[i]==56){
      cpfInt[n]=8;
      n++;
    }
    if (cpf[i]==57){
      cpfInt[n]=9;
      n++;
    }
  }

  // Verifica se tem numeros a mais, ou a menos, no cpf
  if (n!=11){
    validades [3]=-1;
    
    return -1;
  }

  j=1;
  soma=0;
  for (i=0;i<9;i++){
  soma=soma+(cpfInt[i]*j);
  j++;
  }

  //Criação do primeiro digito verificador
  digitoVerificador1 = soma%11;

  if (digitoVerificador1==10){
    digitoVerificador1=0;
  }

  soma=0;
  
  for (i=0;i<10;i++){
  soma=soma + (cpfInt[i]*i);
  }

  // Criação do segundo dígito verificador
  digitoVerificador2 = soma%11;

  if (digitoVerificador2==10){
    digitoVerificador2=0;
  }

  //Verifica ambos os numeros verificadores no cpf
  if (digitoVerificador1==cpfInt[9] && digitoVerificador2==cpfInt[10]){
    validades [3] = 0;
  }

  else {
    validades [3] = -1;
  }
  
}

