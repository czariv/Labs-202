//cesar guedes carneiro 261031
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//professor eu tinha achado o enunciado muito confuso e não entendi o real objetivo do lab por um bom tempo, o motivo disso foi que na minha opinião a introducao assim como os exemplos escolhidos passavam outra ideia
//eu pensei q o objetivo do codigo era mostrar o minimo de substituicoes necessarias para organizar a lista e so fui entender o real objetivo depois de pesquisar na internet, isso porque os testes abertos eram irrealizaveis na mao
//ja que todos tinham um numero muito grande de entradas.
double merge(int arr[], int temp[], int left, int mid, int right){ 
	int i, j, k; 
	double inv_count = 0; 
	i = left; 
	j = mid; 
	k = left;
	while ((i <= mid - 1) && (j <= right)){ 
		if (arr[i] <= arr[j]){ 
			temp[k++] = arr[i++]; 
		} 
		else{ 
			temp[k++] = arr[j++];
			inv_count = inv_count + (mid - i); 
		} 
	} 
	while (i <= mid - 1) 
		temp[k++] = arr[i++]; 
	while (j <= right) 
		temp[k++] = arr[j++]; 
	for (i = left; i <= right; i++) 
		arr[i] = temp[i];
	return inv_count; 
} 

double mergeSort(int lista[], int copia[], int inicio, int final){ 
	int meio;
	double cont = 0; 
	if (final > inicio){ 
		meio = (final + inicio) / 2;
		cont+=mergeSort(lista, copia, inicio, meio); 
		cont+=mergeSort(lista, copia, meio + 1, final);
		cont+=merge(lista, copia, inicio, meio + 1, final); 
	} 
	return cont; 
}

int main(){ 
	int amigos;
	scanf("%d",&amigos);
	int*lista=malloc(sizeof(int) * amigos);
	for(int i=0;i<amigos;i++){
	   scanf("%d",&lista[i]);
	}
    int*copia=(int*)malloc(sizeof(int) * amigos);
    printf("%.0f\n",mergeSort(lista,copia,0, amigos-1));
    
} 