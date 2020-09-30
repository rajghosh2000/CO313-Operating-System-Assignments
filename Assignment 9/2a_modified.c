#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>

void userfunc(int sigid)
{
    FILE * fp;
   /* open the file for writing*/ 
    int child_pid = fork();
    int exit_code;
    char pro_id[10];
    char signal_id[10];
    /*
        The text file is used to store the pid of the program so that it can accsessed in the 2b code so that this program can be killed .
    */
    if (fp = fopen("textfile.txt","w")) 
    {
        if (child_pid < 0)
        {
            printf("Fork error\n");
            exit(1);
        }
           

        if (child_pid == 0)
        {
            exit_code = getpid();
            int sent = getppid();
            sprintf(pro_id,"%d",sent); //sprintf converts int to String for the  text file
            fprintf(fp,pro_id);

            fprintf(fp," ");

            sprintf(signal_id,"%d",sigid); //sprintf converts int to String for the  text file
            fprintf(fp,signal_id);
            
            fclose (fp);

            printf("Child pid : %d and MyParent Id : %d\n",getpid(),getppid());
            
            exit(exit_code);
        }
        else
        {
            printf("You have sent SIGINT signal!!!\n");
            printf("Signal ID is : %d\n",sigid);
            wait(&exit_code);
        }
        
        /* close the file*/    
    }
    else {
        printf("file doesn't exist");
    }
    

}

int main(int argc, char **argv)
{
    
    printf("Click Ctrl+C to check out the function:\n");

    signal(SIGINT,userfunc);  /* here the cursor stops and waits for the interrupt to be called.As the interrupt is called it executes the function which is sent as the 2nd parameter for the given signal function. The first parameter takes in the interrupt key which is CTRL + C here.*/
    while(1);  /* For the program to execute and for a delay and indefinite loop */
    return 0;
}