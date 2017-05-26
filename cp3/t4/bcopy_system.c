#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

#define MAX_SIZE 1024

int main(int argc,char *argv[]){


    int fdin = open("file.in",O_RDONLY);

    int fdout = open("file.out",O_WRONLY|O_CREAT|O_TRUNC);


    char buf[MAX_SIZE];
    memset(buf,'\0',MAX_SIZE);

    int n = -1;

    while((n = read(fdin,buf,MAX_SIZE)) >0){
    
        write(fdout,buf,n);
    
    }

    close(fdin);
    close(fdout);

    return 0;
}
