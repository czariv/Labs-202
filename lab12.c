//cesar guedes carneiro 261031
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int* achador(int** mat,int n,int b,int a,int prof){
    int *ger=malloc(sizeof(int)*2),*att=malloc(sizeof(int)*2),check=0;
    for(int i=0;i<n;i++){
        if(mat[a][i]){
            check++;
            if(i==b){
                ger[1]=ger[0];
                ger[0]=mat[a][i]+prof;
            }
            else{
                mat[a][i]=0;
                att=achador(mat,n,b,i,prof+mat[i][a]);
                if(att[0]<ger[0]||ger[0]==0){
                    ger[1]=ger[0];
                    ger[0]=att[0];
                }
                else if(att[0]<ger[1]||ger[1]==0){
                    ger[1]=att[0];
                }
                if(att[1]<ger[1]||ger[1]==0){
                    ger[1]=att[1];
                }
            }
        }
    }
    if(check==1){
        ger[1]=ger[0];
    }
    if(check==0){
        ger[0]=10000000;
        ger[1]=ger[0];
    }
    return ger;
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
    int *result=(int*)malloc(sizeof(int)*2);
    result=achador(matriz,n,n-1,0,0);
    printf("%d\n",result[1]);
}