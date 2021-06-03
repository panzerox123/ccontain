#include<stdio.h>
#include<string.h>
#include"container.h"

int main(int argc, char * argv[]){
    if (argc < 2) {
        printf("Usage: ccontain run <command>\n");
        return -1;
    }
    if(strcmp("run", argv[1])==0){
        int r = start_container(argc, argv);
        if(r < 0) {
            printf("Failed to start container.\n");
        }
        return -1;
    } else {
        printf("Bad Command:%s\n", argv[1]);
        return -1;
    }
    return 1;
}