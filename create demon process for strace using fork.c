/*This program will give knowledge for stace , fork , execv , system , waitpid all  these system calls */
#include <stdio.h>
#include <stdlib.h>
#include <uv.h>
#include <unistd.h>
#include<string.h>
#include <sys/types.h>
#include <errno.h>  
#include <sys/wait.h>

void runcmd()
{
  pid_t cpid;
  pid_t child_pid;
  int status;
  int j;
	const size_t max_pid_len = 12;// Could be system dependent.
	char *programName = "strace";
  /*parsecmd(cmd,argv);*/
	int pid = getpid();

	printf("parent process pid = %d\n",pid);

	char * mypid = malloc(max_pid_len + 1);
	snprintf(mypid, max_pid_len, "%d", pid);
	printf("string pid= %s\n",mypid);
	char *args[] = {programName, "-p" ,mypid,"-o", "/tmp/strace.log", NULL};

  char final_command[50] = "strace -p ";
    char file[] = " -o /tmp/strace.log";
    strcat(final_command,mypid);
    printf("first attampt String: %s\n", final_command);
    strcat(final_command,file);
    printf("final String: %s\n", final_command);
    
    
  
  child_pid = fork();
  if(child_pid == 0) {
    /* This is done by the child process. */
    printf("child process pid=%d\n",getpid());
    cpid = getpid();
    printf("child process pid cpid =%d\n",cpid);
    printf("child block\n");
  
    /*execv(programName, args);*/
    /*system("strace -p 47091 -o /tmp/strace.log");*/
    system(final_command);
    /* If execv returns, it must have failed. */

    printf("Unknown command\n");
    exit(0);
  }
  else {
     /* This is run by the parent.  Wait for the child
        to terminate. */

  
        system("ls");
        for(j=0;j<10;j++)
        {
          sleep(1);
          printf("%d ",j);
        }
        system("ls");
        printf("\n");
        for(j=11;j<20;j++)
        {
          sleep(1);
          printf("%d ",j);
        }
        printf("abc\n");
        printf("d\n");
        /* if (waitpid(child_pid, &status, 0) > 0) {
              
            if (WIFEXITED(status) && !WEXITSTATUS(status)) 
              printf("program execution successful\n");
              
            else if (WIFEXITED(status) && WEXITSTATUS(status)) {
                if (WEXITSTATUS(status) == 127) {
  
                    // execv failed
                    printf("execv failed\n");
                }
                else 
                    printf("program terminated normally,"
                       " but returned a non-zero status\n");                
            }
            else 
               printf("program didn't terminate normally\n");            
        } 
        else {
           // waitpid() failed
           printf("waitpid() failed\n");
        }*/
        
      /*exit(0);*/
     /* printf("cpid+1=%d\n",cpid+1);
      printf("cpid+1=%d\n",cpid+2);
    kill(cpid+1, SIGTERM);
    kill(cpid+2, SIGTERM);*/
   }
   
  }


int main()
{
  runcmd();
  return 0;
}
