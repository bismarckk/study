#include<sys/types.h>
#include<unistd.h>
#include<iostream>

int main (int argc, char *argv[])
{
      pid_t newProc;
      char *pathToSh ="ls";
      char *newargv[] = { "ls","-la",NULL };      
      
      std::cout<<"to jest moj bash: ";
       
            newProc = fork();
            if (newProc>0)
            {
                            
                  execvp(pathToSh, newargv);                  
                  
            }
       
      return 0;
}