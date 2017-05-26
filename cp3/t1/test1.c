#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc,char* argv[]){


    const char *buf = "Here is some data\n";


    if(write(1,buf,18) != 18)
        write(2,"write buf occured some error\n",strlen("Write buf occured some error\n"));

    return 0;
}
