#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

#define MAX_SIZE 1024


int main(int argc,char *argv[]){


    char pData[MAX_SIZE];
    memset(pData,'a',MAX_SIZE-2);
    pData[MAX_SIZE-1] = '\0';

    //snprintf(pData,"%s","Write data to file aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");

    int nLeft = 1024*1024;

    int fd = open("file.in",O_WRONLY| O_CREAT|O_TRUNC);

    if(fd <0){
    
        printf("open file error\n");
        exit(1);
    }

    while(nLeft >=0){
    
        int n = write(fd,pData,strlen(pData));

        if(n <0){
        
            printf("write error\n");
            close(fd);
            break;
        }
        nLeft -= n;
    }


    close(fd);
    return 0;
}
