#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    printf("\nI m the other program called in betwwen by the grandChild : \n");
    printf("\tFirst I will print the infos sent to me from the main prog : \n");

    for(int i=0;i<argc;i++){
        printf("\t\t%s\n",argv[i]);
    }

    printf("Back to me i.e. the new prog print : Hello world!!!\n\n");
}