#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_RLEN 50

	char* decode(char* src){
		int rLen;
		char count[MAX_RLEN];
		int lenn = strlen(src);
		char* dest = (char*)malloc(sizeof(char) * (100));

		int i, j, k=0;

		char holdNonDigit[1];
		char storeDigit[20];
		int numPlace = 0;
		for(i = 0;i<lenn;i++){
			if(!(isdigit(src[i]))&& numPlace>0){
				int numLength = atoi(storeDigit);
				for(j = 0;j<numLength;j++){
					dest[k] = holdNonDigit[0];
					k++;
				}
				storeDigit[0] = 0;
			}
			if(!(isdigit(src[i]))){
				holdNonDigit[0] = src[i];
				numPlace = 0;
			}
			if(isdigit(src[i])){
				storeDigit[numPlace] = src[i];
				numPlace++;
				storeDigit[numPlace] = 0;
			}
		}
		dest[k] = '\0';
		return dest;
	}
	
	int main(int argc, char *arg[])
	{
		
		if(argc<1){
		printf("my-unzip: file1 [file2 ...]\n");
		exit(1);
		}
		char *line = NULL;
		size_t len = 0;
		ssize_t nread;
		for(int i = 1;i<argc;i++){
		FILE *fp = fopen(arg[i], "r");
			if(fp == NULL){
				printf("cannot open file\n");
				exit(1);
			}
		while((nread = getline(&line, &len, fp)) != -1){
			char str[len];
			strncpy(str, line, sizeof str - 1);
			str[len] = '\0';
			char* res = decode(str);
			printf("%s", res);

		}
		int closeCheck = fclose(fp);
		if(closeCheck != 0){
				printf("file close failure\n");
				exit(1);
		}}
		return 0;
	}
