#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_RLEN 50

	char* encode(char* src)
	{
		int rLen;
		char count[MAX_RLEN];
		int lenn = strlen(src);

		char* dest = (char*)malloc(sizeof(char) * (lenn * 2 + 1));

		int i, j = 0, k;

		for(i = 0;i<lenn;i++){
			dest[j++] = src[i];
			rLen = 1;
			while(i + 1< lenn && src[i] == src[i+1]){
				rLen++;
				i++;
			}

			sprintf(count, "%d", rLen);

			for(k = 0; *(count + k); k++, j++){
				dest[j] = count[k];
			}
		}
		dest[j] = '\0';
		return dest;
	}
	int main(int argc, char *arg[])
	{
		if(argc<1){
		printf("my-zip: file1 [file2 ...]\n");
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
			char* res = encode(str);
			printf("%s", res);

		}
		int closeCheck = fclose(fp);
		if(closeCheck != 0){
				printf("file close failure\n");
				exit(1);
		}}
		return 0;
	}
