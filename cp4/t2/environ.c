#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(int argc,char *argv[]){


	if(argc <2){
	
		perror("usage:function enviro\n");
		exit(1);
	}


	char *ptr = argv[1];

	char *env = getenv(ptr);

	if(env != NULL){
	
		printf("%s old vlaue %s\n",ptr,env);
	}
	else{
	
		printf("no such environment\n");

		//exit(1);
	}

	if(argc ==3){
	
		char *value = argv[2];

		char pValue[128];
		memset(pValue,'\0',128);

		snprintf(pValue,128,"%s=%s",ptr,value);

		if(putenv(pValue) != 0){
		
			fprintf(stderr,"put %s error\n",pValue);
			exit(1);
		}

		env = getenv(ptr);

		printf("%s new value is %s\n",ptr,env);
	}

	return 0;

}
