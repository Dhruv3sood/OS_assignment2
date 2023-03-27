#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
// #include <errno.h>
// is it needed?
#include <stdio.h>
#include <unistd.h>

void printError(){
    perror("Directory could not be created using the command (mkdir)");
}

void append(char *a,char b){
    char c[2];
    c[0]=b;
    c[1]=0;
    strcat(a,c);
}

int get(char cwd[]){
    return getcwd(cwd,sizeof(cwd));
}

int arg1=1;
int arg2=2;
int proper;
char cdchange[1000];

int main(int argc, char const* argv[]){
    
    char* prime = argv[0];
    char string[100];

    if (prime==NULL){
        perror("Missing Argument\n");
    }

    if (argc==1){
        proper=mkdir(argv[0],0700);
        if (proper<0){
            printError;
        }
    }
    else{

    if (argv[arg1]!=NULL && argv[arg1]=="-p"){
        proper= mkdir(argv[arg1],0700); 
        char *ptr=strtok(prime,"/");
        while (ptr!=NULL){
            proper = mkdir(ptr,0700);
        if(proper<0){
            printError;
        }
        get(cdchange[1000]);
        append(cdchange,'/');
        puts(cdchange);
        append(cdchange,ptr);
        puts(cdchange);
}
    }
    
    else if((argv[arg1]!=NULL && argv[arg1]=="-v")){
        proper=mkdir(argv[arg1],0700);
        if(proper<0){
            printError;
        }
        else {
            printf("Directory created using the command (mkdir)");
        }
    
    }
    else {
        perror("Invalid option");
    }


    return 0;

    }
}

    








