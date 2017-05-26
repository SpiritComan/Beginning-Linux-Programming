#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/mman.h>

#define MAX_SIZE 128

#define MAX_RECORD 100

typedef struct RECORD{

    int value;
    char info[MAX_SIZE];
}record;


int main(int argc,char *argv[]){

    record records;

    record *maped;


    fputs("hello world\n",stdout);

    FILE *fp = fopen("data.dat","wb");
    int i = 0;

    for(; i <MAX_RECORD; ++i){
    
        records.value = i+1;
        sprintf(records.info,"RECORD-%d",i+1);
        fwrite(&records,sizeof(record),1,fp);
    }

    fclose(fp);
    
    fp = fopen("data.dat","rb+");

    fseek(fp,43*sizeof(record),SEEK_SET);
    fread(&records,sizeof(record),1,fp);


    char buf[128];
    memset(buf,'\0',128);


    sprintf(buf,"value:%d info:%s\n",records.value,records.info);

    fputs(buf,stdout);

    //printf("value:%d  info:%s\n",maped->value,maped->info);

    fclose(fp);

    fp = fopen("data.dat","wb");
    records.value = 144;
    sprintf(records.info,"RECORD-%d",144);

    //fseek(fp,-43*sizeof(record),SEEK_CUR);

    fseek(fp,43*sizeof(record),SEEK_CUR);

    fwrite(&records,sizeof(record),1,fp);

    fclose(fp);


    int fd = open("data.dat",O_RDWR);

    maped = (record*)mmap(NULL,MAX_RECORD*sizeof(record),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);


    memset(buf,'\0',128);
    sprintf(buf,"value:%d info:%s\n",maped[43].value,maped[43].info);

    fputs(buf,stdout);
    //printf("value:%d info:%s\n",maped[43].value,maped[43].info);

    maped[43].value = 211;
    sprintf(maped[43].info,"RECORD-%d",211);

    msync((void*)maped,MAX_RECORD*sizeof(record),MS_ASYNC);

    munmap((void*)maped,MAX_RECORD*sizeof(record));

    close(fd);


    return 0;
}

