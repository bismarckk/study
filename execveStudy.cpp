#include<sys/types.h>
#include<unistd.h>
#include<iostream>
#include<signal.h>
#include<stdlib.h>
#include<sys/wait.h>
void sig_handler(int mySignal);
void studyAtExit();
void sig_chld (int mysignal);

int main (int argc, char *argv[])
{
      
      
      pid_t newProc;
      char *pathToSh[] ={"ls", NULL};
      char *newargv[] = { "ls","-la",NULL };

      if(signal(SIGINT, sig_handler)==SIG_ERR);
      
      atexit(studyAtExit);
                  
            newProc=fork();
            if (newProc==0)
            {    
                  
                  //kill(getpid(),SIGKILL); 
                  std::cout<<"\ndziecko";                                     
                  execvp(pathToSh[0], newargv);
                  exit(0);       
            }else if (newProc>0)
            {
                  newProc=wait(NULL);
            }
            
      std::cout<<"parent";
     
       
      return 0;
}

void sig_handler(int mySignal)
{
      if(mySignal==SIGINT)
      {
            std::cout<<"i get signal\n";
      }                
      
}
void sig_chld (int mysignal)
{
       pid_t pid;
            int status;
            pid = wait(&status); 
}


void studyAtExit()
{
      std::cout<<"\nwyswietlam po zakonczeniu\n";
}