#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char* arg[])
{
	if(argc<2){
		printf("my-grep: searchterm [file ...]\n");
		exit(1);
	}
	char *line = NULL;
	const char *needle = arg[1];
	size_t len = 0;
	ssize_t nread;
	if(argc==2){
		printf("Please enter a sentence\n");
		nread = getline(&line, &len, stdin);
		if(strstr(line, needle) != NULL){
		printf("Bullseye\n");
		}
		exit(0);
	}
	else{
	for(int i = 2;i<argc;i++){
	FILE *fp = fopen(arg[i], "r");
			if(fp == NULL){
				printf("cannot open file\n");
				exit(1);
		}
	while((nread = getline(&line, &len, fp)) != -1) {
		printf("Retrieved line of length %zu:\n", nread);
		printf("%s", line);
		if(strstr(line, needle) != NULL){
			printf("Bullseye\n");
		}
	}
	int closeCheck = fclose(fp);
	if(closeCheck != 0){
		printf("file close failure\n");
		exit(1);
	}}}
}
