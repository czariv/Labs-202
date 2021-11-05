//cesar guedes carneiro 261031
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct lista{
    struct lista* esq;
    struct lista* dir;
    int numero;
    int altura;
}lista;
int add(lista* cabeca,int n){
    if(n>cabeca->numero){
        if(cabeca->dir)
            return add(cabeca->dir,n);
        else{
            cabeca->dir=(lista*)malloc(sizeof(lista));
            cabeca->dir->numero=n;
            cabeca->dir->altura=cabeca->altura;
            cabeca->dir->altura++;
            cabeca->dir->dir=NULL;
            cabeca->dir->esq=NULL;
            return cabeca->dir->altura;
        }
    }
    if(n<cabeca->numero){
        if(cabeca->esq)
            return add(cabeca->esq,n);
        else{
            cabeca->esq=(lista*)malloc(sizeof(lista));
            cabeca->esq->numero=n;
            cabeca->esq->altura=cabeca->altura;
            cabeca->esq->altura++;
            cabeca->esq->dir=NULL;
            cabeca->esq->esq=NULL;
            return cabeca->esq->altura;
        }
    }
    return 0;
}
int adcont(lista* cabeca,int amax,int k,int n){
    int m,aatt;
    while(++k<n){
        scanf("%d",&m);
        aatt=add(cabeca,m);
        if(aatt>amax)
            amax=aatt;
        aatt=0;
    }
    return amax;
}
int main(){
    int n,mdn,mm;
    scanf("%d",&n);
    if(!(n)){
        printf("0 0\n");
        return 0;
    }
    lista* cabecadn=(lista*)malloc(sizeof(lista));
    lista* cabecam=(lista*)malloc(sizeof(lista));
    cabecadn->dir=NULL;
    cabecadn->altura=1;
    cabecadn->esq=NULL;
    cabecam->dir=NULL;
    cabecam->altura=1;
    cabecam->esq=NULL;
    scanf("%d",&mdn);
    cabecadn->numero=mdn;
    mdn=adcont(cabecadn,0,0,n);
    scanf("%d",&mm);
    cabecam->numero=mm;
    mm=adcont(cabecam,0,0,n);
    printf("%d %d\n",mdn,mm);
}