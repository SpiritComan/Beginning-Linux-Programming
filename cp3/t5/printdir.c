#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

void printdir(const char *path,int depth){


    DIR *dir;
    struct dirent *dirinfo;


    
    struct stat st;
    if((dir = opendir(path)) == NULL){
    
        printf("open dir %s error\n",path);

        printf("ssssssssss\n");
        return;
        
    }


    chdir(path);


    while((dirinfo = readdir(dir)) != NULL){
    
        lstat(dirinfo->d_name,&st);

        if(S_ISDIR(st.st_mode)){
        
            //is dir

            if(strcmp(".",dirinfo->d_name) == 0 || strcmp("..",dirinfo->d_name) == 0){
            
                continue;
            }
            printf("%*s%s/\n",depth,"",dirinfo->d_name);
            printdir(dirinfo->d_name,depth+4);

        }
        printf("%*s%s\n",depth,"",dirinfo->d_name);
    }

    chdir("..");
    closedir(dir);
}

int main(int argc,char *argv[]){


    char dir[128];
    memset(dir,'\0',128);

    printf("input scanddir(like /home)\n");

    fgets(dir,128,stdin);

    if(dir[strlen(dir)-1] == '\n')
        dir[strlen(dir) -1] = '\0';
    printf("begin scanddir  %s\n",dir);


    printdir(dir,0);

    printf("end scandir");


    return 0;
}
