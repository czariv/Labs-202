//cesar guedes carneiro 261031
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void merge(int arr[], int temp[], int left, int mid, int right){ 
	int i, j, k; 
	i = left; 
	j = mid; 
	k = left;
	while ((i <= mid - 1) && (j <= right)){ 
		if (arr[i] <= arr[j]){ 
			temp[k++] = arr[i++]; 
		} 
		else{ 
			temp[k++] = arr[j++]; 
		} 
	} 
	while (i <= mid - 1) 
		temp[k++] = arr[i++]; 
	while (j <= right) 
		temp[k++] = arr[j++]; 
	for (i = left; i <= right; i++) 
		arr[i] = temp[i]; 
} 
void mergeSort(int lista[], int copia[], int inicio, int final){ 
	int meio; 
	if (final > inicio){ 
		meio = (final + inicio) / 2;
		mergeSort(lista, copia, inicio, meio); 
		mergeSort(lista, copia, meio + 1, final);
		merge(lista, copia, inicio, meio + 1, final); 
	} 
}

int main(){ 
	int quantidade,perfeito;
	scanf("%d",&quantidade);
	scanf("%d",&perfeito);
	int*lista=malloc(sizeof(int) * quantidade);
	for(int i=0;i<quantidade;i++){
	   scanf("%d",&lista[i]);
	}
    int*copia=(int*)malloc(sizeof(int) * quantidade);
    mergeSort(lista,copia,0, quantidade-1);
    printf("%d\n",lista[perfeito-1]);
    
} 