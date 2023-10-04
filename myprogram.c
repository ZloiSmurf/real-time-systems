/* ИМЯ: Манкевич Сергей
 * ДАТА: 28.04.2023
 * ИМЯ ФАЙЛА: myprogramm.c
 * НАЗНАЧЕНИЕ: Вывод пользовательского текста на экран
 */

#include <stdio.h>
#include <unistd.h>

int main(){
	char str[80];
	printf("The first program\nEnter a string up to 79 characters\n");
   	fgets(str, 80, stdin);
   	printf("Dango says: %s\n", str);

   
   return 0;
}
