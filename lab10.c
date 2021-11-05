//cesar guedes carneiro 261031
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(){
    int n, k,hash,repeticoes=0;
    scanf("%d",&n);
    int*lista=malloc(sizeof(int)*n);
    if(n==0){
        printf("0\n");
        return 0;
    }
    for(int i=0;i<n;i++){
        scanf("%d",&k);
        hash=k%n;
        while(lista[hash]){
            repeticoes++;
            hash++;
            if(hash>n-1)
                hash=0;
        }
        lista[hash]=k+1;
        /*Adotei essa maneira de armazenar os numeros na lista para prevenir
        que um eventual 0 na sequencia de numeros fosse ignorado, se fosse
        preciso recuperar os numeros dessa lista somente seria preciso diminuir 1 de cada um.
        Estou assumindo porem que nao seriam possiveis numeros negativos na sequencia*/
    }
    printf("%d\n",repeticoes);
    return 0;
}