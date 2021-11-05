//cesar guedes carneiro 261031
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct lista{
    struct lista* prox;
    struct lista* ant;
    int numero;
}lista;
int main(){
    char num[24];
    int n, numero;
    lista* cabeca, *anterior, *atual;
    scanf("%s",num);
    n=strlen(num);
    cabeca=(lista*)malloc(sizeof(lista));
    if(n==1){
        cabeca->prox=cabeca;
        cabeca->ant=cabeca;
        cabeca->numero=num[0]-'0';
    }
    else{
        atual=cabeca;
    }
    for(int i=0;i<n;i++){
        if(i==n-1){
            atual->prox=cabeca;
            cabeca->ant=atual;
        }
        else
            atual->prox=(lista*)malloc(sizeof(lista));
        if(i)
            atual->ant=anterior;
        atual->numero=num[i]-'0';
        anterior=atual;
        atual=atual->prox;
    }
    scanf("%d",&numero);
    atual=cabeca;
    int contador=0;
    for(int i=0;i<numero;i++){
        while(atual->numero<=atual->prox->numero && contador<22){
            atual=atual->prox;
	    contador++;
        }
	contador=0;
        if(atual==cabeca){
            cabeca=atual->prox;
        }
        atual->prox->ant=atual->ant;
        atual->ant->prox=atual->prox;
        atual=cabeca;
    }
    int j=n-numero;
    int teste=0;
    for(int i=0;i<j;i++){
        if(teste==0){
       	    if(cabeca->numero==0){
		cabeca=cabeca->prox;
		    continue;
	    }
	}
        printf("%d",cabeca->numero);
        cabeca=cabeca->prox;
	teste++;
    }
    if(teste==0){
        int i=0;
	printf("%d",i);
    }
}