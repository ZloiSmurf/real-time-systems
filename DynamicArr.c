/* ИМЯ: Манкевич Сергей
 * ДАТА: 10.10.2023
 * ИМЯ ФАЙЛА: DynamicArr.c
 * НАЗНАЧЕНИЕ ПРОГРАММЫ: Создание двух динамических массивов, вывод их содержимого и адресов
 */

#include <stdio.h>
#include <stdlib.h>

//Displays the elements and adresses of a 1D array
void ArrayOneDim(int length){
	int *arr = (int*)malloc(length*sizeof(int));
	printf("1D array:\nPointer adress %p, %p\n", &arr, arr);
	for (int i=0; i<length; i++){
		arr[i] = i;
	}
	for (int i=0; i<length; i++){
		printf("Value = %d; Adress = %p\n", arr[i], &arr[i]);
	}
	free(arr);
}

//Display the elements and adresses of a 2D array
void ArrayTwoDim(int x, int y){
	int **arr = (int**)malloc(x * sizeof(int*));
	printf("2D array:\nPointer adress %p, %p\n", &arr, arr);
	for (int i=0; i<x; i++){
		arr[i] = (int*)malloc(y*sizeof(int));
		for (int j=0; j<y; j++){
			arr[i][j] = i+j;
		}
	}
	for (int i=0; i<x; i++){
		printf("Row adress: %p\n", &arr[i]);
		for (int j=0; j<y; j++){
			printf("arr[%d][%d]; Value = %d; Adress = %p\n",i, j, arr[i][j], &arr[i][j]);
		}
	}
	for (int i=0; i<x; i++){
		free(arr[i]);
	}
}

int main(){
	int len;
	int x, y;
	printf("Enter the length of the 1D array\n");
	scanf("%d", &len);
	printf("Enter the length of the 2D array x and y\n");
	scanf("%d", &x);
	scanf("%d", &y);
	ArrayOneDim(len);
	ArrayTwoDim(x, y);
	return 0;
}
