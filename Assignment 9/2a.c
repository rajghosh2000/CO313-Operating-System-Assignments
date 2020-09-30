#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>

void userfunc()
{
    /*
        This is the user defined code i.e when the interrupt is called using CTRL + C then this function is called the output is shown as the pid and ppid of the fork process.
    */
    int child_pid = fork();
    int exit_code;
    if (child_pid < 0)
    {
        printf("Fork error\n");
        exit(1);
    }

    if (child_pid == 0)
    {
        printf("Child pid : %d and MyParent Id : %d\n",getpid(),getppid());
        exit_code = getpid();
        exit(exit_code);
    }
    else
    {
        printf("\nMy child's with PID : %d exit status is: %d\n", child_pid ,WEXITSTATUS(exit_code));
        wait(&exit_code);
    }
}

int main()
{
    printf("Click Ctrl+C to check out the function:\n");

    signal(SIGINT,userfunc);  /* here the cursor stops and waits for the interrupt to be called.As the interrupt is called it executes the function which is sent as the 2nd parameter for the given signal function. The first parameter takes in the interrupt key which is CTRL + C here.*/
    while(1);  /* For the program to execute and for a delay and indefinite loop */
    return 0;
}