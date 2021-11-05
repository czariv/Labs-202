#include <stdlib.h>
#include <stdio.h>
void achador(int** mat,int n,int b,int* menor,int* seg, int a,int prof){
    if((prof>*seg || prof>45) && *seg){
        return;
    }
    if(mat[a][0]==-1){
        return;
    }
    int salvador;
    for(int i=n-1;i>=0;i--){
        if(mat[a][i]){
            if(i==b){
                if(prof+mat[a][i]<*menor||*menor==0){
                    *seg=*menor;
                    *menor=prof+mat[a][i];
                }
                else if(prof+mat[a][i]<*seg||*seg==0){
                    *seg=prof+mat[a][i];
                }
            }
            else{
                salvador=mat[a][i];
                mat[i][a]=0;
                mat[a][i]=0;
		mat[a][0]=-1;
                achador(mat,n,b,menor,seg,i,salvador+prof);
		mat[a][0]=0;
                mat[i][a]=salvador;
                mat[a][i]=salvador;
            }
        }
    }
}
int main(){
    int n,m,i,j,t,b;
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
    int *menor,*segundo;
    t=0;
    b=0;
    menor=&t;
    segundo=&b;
    achador(matriz,n,n-1,menor,segundo,0,0);
    printf("%d\n",b);
}