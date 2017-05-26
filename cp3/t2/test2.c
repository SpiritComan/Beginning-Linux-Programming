#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define MAX_SIZE 128
int main(int argc,char **argv){


    char  buf[MAX_SIZE];
    memset(buf,'\0',MAX_SIZE);

    if(read(0,buf,MAX_SIZE-1) >0)
        write(1,buf,strlen(buf));
    else
       write(2,"read error\n",strlen("read error\n"));

    return 0;
}
