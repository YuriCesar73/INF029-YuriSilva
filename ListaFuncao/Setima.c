#include <stdio.h>
#include <string.h>
#define TAM 3
#define len 100
void lerPalavras (char a[], char b[], char c[]);

int main (){

char a [len];
char b [len];
char c [len];

lerPalavras (a,b,c);

printf("%s\n",a);
printf("%s\n",b);
printf("%s\n",c);
}

void lerPalavras (char a[], char b[], char c[]){
int tamanho; 
  
  printf("Digite a primeira palavra: ");
  fgets (a,len,stdin);
  tamanho= strlen (a); 

		if (a [tamanho-1]=='\n'){
        a [tamanho-1]='\0';
      }
  
  printf("Digite a segunda palavra: ");
  fgets (b,len,stdin);
  //getchar();
  tamanho= strlen (b); 
    if (b [tamanho-1]=='\n'){
        b [tamanho-1]='\0';
      }
  
  printf("Digite a terceira palavra: ");
 fgets (c,len,stdin);
  //getchar();
  tamanho= strlen (c);
    if (c [tamanho-1]=='\n'){
        c [tamanho-1]='\0';
      }
  
}



