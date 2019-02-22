#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char* arg[])
{
	char buffer[1000];
	for(int i = 1;i<argc;i++){
	FILE *fp = fopen(arg[i], "r");
	if(fp == NULL){
		printf("cannot open file\n");
		exit(1);
	}

	while(fgets(buffer, 1000, fp) != NULL){
	printf("%s", buffer);
	}
	int closeCheck = fclose(fp);
	if(closeCheck !=0){
		printf("file closing failure\n");
		exit(1);
	}}
	return 0;
}


