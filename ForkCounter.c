/* ИМЯ: Манкевич Сергей
 * ДАТА: 28.09.2023
 * ИМЯ ФАЙЛА: ForkCounter.c
 * НАЗНАЧЕНИЕ ПРОГРАММЫ: Организация итарационных циклов в родительском и дочернем процессе
*/

#include <unistd.h>
#include <stdio.h>

#define MAX_COUNT 200

void ChildProcess(){
	/*
	for(int i=0;i<MAX_COUNT;i++){
		//printf("This line is from child, value = %d\n", i);
	}
	*/
	execl("/bin/ls", "ls", "-l", NULL);
}

void ParentProcess(){
	for(int i=0; i<MAX_COUNT; i++){
		printf("This line is from parent, value = %d\n", i);
	}
}


int main(){
	int pid;
	pid = fork();
	if(pid!=0){
		ParentProcess();
	}
	else{
		ChildProcess();
	}
	return 0;
}
