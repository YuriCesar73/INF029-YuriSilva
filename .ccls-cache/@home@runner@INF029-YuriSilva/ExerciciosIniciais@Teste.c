#include <stdio.h>
#include <string.h>
int main (){

  char comp [15];
  char c [100];
  int cpf [11];
  int i,j;
  int soma;
  int tamanho;
  int n;
  int digitoVerificador1, digitoVerificador2;
  n=soma=0;
  printf("Digite o cpf: \n");
  fgets (c,100,stdin);

  tamanho = strlen (c);
    if(c[tamanho-1]=='\n'){
      c[tamanho-1] = '\0';
    }

/*for (i=0;c[i]!='\';i++){
  if (c[i] >= 48 && c[i] <= 57){
    n [i]= 
  }
}*/
  
  for (i=0;c[i]!='\0';i++){

    if (c[i]==48){
      cpf[n] = 0;
      comp [n] = '0';
      n++;
      
    }
     if (c[i]==49){
       cpf[n] = 1;
        comp [n] = '1';
       n++;
    }
     if (c[i]==50){
       cpf[n] = 2;
        comp [n] = '2';
       n++;
    }
     if (c[i]==51){
       cpf[n] = 3;
        comp [n] = '3';
       n++;
    }
     if (c[i]==52){
       cpf[n] = 4;
        comp [n] = '4';
       n++;
    }
     if (c[i]==53){
       cpf[n] = 5;
        comp [n] = '5';
       n++;
    }
     if (c[i]==54){
       cpf[n] = 6;
        comp [n] = '6';
       n++;
    }
     if (c[i]==55){
       cpf[n] = 7;
        comp [n] = '7';
       n++;
    }
     if (c[i]==56){
       cpf[n] = 8;
         comp [n] = '8';
       n++;
    }
     if (c[i]==57){
       cpf[n] = 9;
      comp [n] = '9';
       n++;
    }
     
  }

  comp [12] = '\0';
  
printf("\n\n\n\n\n\n");


  printf("%d\n",n);
  if (n>11){
    return -1;
  }
for (i=0;i<11;i++){
  printf("%d",cpf[i]);
}
  printf("\n");
  
  for (i=0;comp[i]!='\0';i++){
  printf("%c",comp[i]);
}

j=1;
for (i=0;i<9;i++){
  soma=soma+(cpf[i]*j);
  j++;
}

  printf("\nA soma deu %d",soma);
  digitoVerificador1 = soma%11;

  printf("\nO digito verificador eh: %d",digitoVerificador1);

  if (digitoVerificador1==10){
    digitoVerificador1=0;
  }

  printf("\n O digito verificador na verdade eh %d",digitoVerificador1);

  soma=0;
  
for (i=0;i<10;i++){
  soma=soma + (cpf[i] * i);
}
digitoVerificador2 = soma%11;

  printf("\n A segunda soma deu: %d",soma);
  printf("\n O segundo dígito verificador eh: %d",digitoVerificador2);

  if (digitoVerificador2==10){
    digitoVerificador2=0;
  }

  printf("\n O valor final do segundo digito verificador eh: %d",digitoVerificador2);

  if (digitoVerificador1==cpf[9] && digitoVerificador2==cpf[10]){
    printf("\n Deu tudo certo aqui pivete");
  }

  
}