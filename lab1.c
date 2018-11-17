 #include <stdio.h>  
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include "wait.h"



  int main (void)
    {
      pid_t status,parent_id,child_id;
      pid_t counter;
      switch( counter=fork( ) )
        {
     case -1:
          exit(1); 
  case 0:
          sleep(5);
          printf("Child process!\n");
          child_id=getpid();
         printf("MY PID -- %d\n",child_id );
          parent_id=getppid();
          printf("Parent PID -- %d\n",parent_id );
          printf("Enter exit-code");
          scanf(" %d/n",&status);
          printf("Exit!\n");
          exit(status);
  default:
          sleep(5);
          printf("Parent process!\n");
          parent_id=getpid();
          printf("MY  PID -- %d\n", parent_id);
          printf("PARENT: PID my child %d\n",counter);
          printf("Waiting for child process to call exit()...\n");
          child_id=waitpid(counter,NULL,WUNTRACED);
          printf("Child status %d\n",child_id);
          printf("Exit!\n");
        }
    
}
