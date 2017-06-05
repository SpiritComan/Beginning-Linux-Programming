#include <stdio.h>
#include <stdlib.h>


int main(int argc,char *argv[]){

	FILE *tmpFile;

	char *tmpname;

	tmpname = tmpnam(NULL);


	if(tmpname != NULL)
		printf("tmp file name is :%s\n",tmpname);

	tmpFile = tmpfile();

	if(tmpFile != NULL)
		printf("Opend a temporary file OK\n");
	else
		printf("Opend a temporary file error\n");


	return 0;
}
