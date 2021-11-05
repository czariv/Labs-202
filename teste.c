//cesar guedes carneiro 261031
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
typedef struct nos{
    int dist;
    int visita;
}nos;
nos* achador(int n, int** matriz, int p, int o){
    int t,j;
    nos* lista=(nos*)malloc(sizeof(nos)*n);
    for (int i=0;i<n;i++){
		lista[i].dist=INT_MAX;
		lista[i].visita=0;
    }
    lista[p].dist=0;
    for (int i=0;i<n;i++){
        t=INT_MAX;
        for(int h=0;h<n;h++){
            if(lista[h].visita==0 && lista[h].dist<=t && h!=o){
                t=lista[h].dist;
                j=h;
            }
        }
        lista[j].visita=1;
        for(int h=0;h<n;h++){
            if(!lista[h].visita && matriz[j][h] && lista[j].dist+matriz[j][h]<lista[h].dist && lista[j].dist!=INT_MAX){
                lista[h].dist=lista[j].dist+matriz[j][h];
            }
        }
    }
    return lista;
}
int main(){
    int n,m,i,j,t;
    scanf("%d %d",&n,&m);
    int** matriz=(int**)malloc(sizeof(int*)*n);
    for(int h=0;h<n;h++){
        matriz[h]=(int*)malloc(sizeof(int)*n);
    }
    for(int h=0;h<m;h++){
        scanf("%d %d %d",&i,&j,&t);
        matriz[i][j]=t;
        matriz[j][i]=t;
    }
    nos *origem, *destino;
    origem=achador(n,matriz,0,n-1);
    destino=achador(n,matriz,n-1,0);
    int segmin=INT_MAX, min=origem[n-1].dist;
    for(int h=1;h<n-1;h++){
        if((origem[h].dist+destino[h].dist)<segmin && (origem[h].dist+destino[h].dist)>min){
            segmin=origem[h].dist+destino[h].dist;
        }
    }
    printf("%d\n",segmin);
}