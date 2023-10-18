/* ИМЯ: Манкевич Сергей
 * ДАТА: 10.10.2023
 * ИМЯ ФАЙЛА: OddDivisible.c
 * НАЗНАЧЕНИЕ: Finding the number of odd numbers and numbers divisible by a function parameter
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void CountOddAndDivisible(int *arr, int size, int divisor, int *oddCount, int *divisibleCount ){
	*oddCount = 0;
	*divisibleCount = 0;

	for (int i=0; i<size; i++){
		printf("arr[%d] = %d\n", i, arr[i]);
		if (arr[i]%2 != 0){
			(*oddCount)++;
		}
		if (arr[i] % divisor ==0) {
			(*divisibleCount)++;
		}
	}
}

int main(){
	int size, divisor, oddCount, divisibleCount;
	int *arr;

	printf("Enter the length of the array: ");
	scanf("%d", &size);
	printf("Enter the divisor: ");
	scanf("%d", &divisor);
	
	arr = (int*)malloc(size * sizeof(int));
	srand(time(NULL));
	for (int i=0; i<size; i++){
		arr[i] = rand() % 1000;
	}
	void (*func)(int*, int, int, int*, int*);
	func = CountOddAndDivisible;
	func(arr, size, divisor, &oddCount, &divisibleCount);
	printf("Number of odd numbers = %d\nThe number of numbers divisible by %d = %d\n", oddCount, divisor, divisibleCount);
	free(arr);	
	return 0;
}
