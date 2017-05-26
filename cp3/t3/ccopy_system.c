#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int main(int argc,char *argv[]){


    int fd = open("file.in",O_RDONLY);

    int fdout = open("file.out",O_WRONLY|O_CREAT|O_TRUNC);


    int n = 0;
    char c;
    while((n = read(fd,(char *)&c,1)) == 1){
    
        write(fdout,&c,1);
    }

    close(fd);
    close(fdout);


    return 0;
}
