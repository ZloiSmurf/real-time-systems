/* ИМЯ: Манкевич Сергей
 * ДДАТА: 25.09.2023
 * ИМЯ ФАЙЛА: textdub.c
 * НАЗНАЧЕНИЕ ПРОГРАММЫ: Перенаправление вывода из терминала в текстовый файл
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
	int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC);
	
	printf("Hello world\n");
	if(fd == -1){
		perror("Could not open the file\n");
		return 1;
	}
	if (dup2(fd, 1) == -1){
		perror("Error when dublicating the file descriptor\n");
		return 1;
	}
	
	printf("This text will be written to the file \"output.txt\"\n");
	
	close(fd);
	dup2(1, STDOUT_FILENO);
 
	return 0;
}

 
