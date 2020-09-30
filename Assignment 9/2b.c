#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>


int main()
{
    char c;
    int i=0,j=0;
    char pid_val[10], sigid[5];
    /*
        The text file is used to get the process id from other code i.e 2a_modified
        So if the 2a_modified code is not executing then this program won't run.
    */
    FILE *file;
    file = fopen("textfile.txt", "r");
    if (file) 
    {
        while ((c = fgetc(file)) != EOF)
            {
                if(c==' ')
                {
                    while ((c=fgetc(file))!= EOF)
                    {
                        sigid[j++] = c;
                    }
                    break;
                }
                pid_val[i++] = c;
            }
        fclose(file);
    }
    int pidlen = i;

    pid_t processID = atoi(pid_val); //atoi is used to convert Sting to int in c
    int signalID = atoi(sigid); //atoi is used to convert Sting to int in c

    int success = kill(processID,SIGKILL);
    if(success == 0){
        printf("Succesful\n");
    }
    else{
        printf("Unsuccessful\n %d",success);
    }
    return 0;
}