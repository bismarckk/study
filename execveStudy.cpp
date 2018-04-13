#include<sys/types.h>
#include<unistd.h>
#include<iostream>
#include<signal.h>
#include<stdlib.h>
#include<sys/wait.h>
void sig_handler(int mySignal);
void studyAtExit();

int main (int argc, char *argv[])
{
      pid_t newProc;
      char *pathToSh[] ={"sh", NULL};
      char *newargv[] = { NULL };

      if(signal(SIGINT, sig_handler)==SIG_ERR);
      signal(SIGCHLD,sig_handler);
      atexit(studyAtExit);
      
      std::cout<<"to jest moj bash: ";
       
            newProc = fork();
            if (newProc==0)
            {     
                  std::cout<<"dziecko";                                     
                  //execvp(pathToSh[0], newargv);
                             
            }

      std::cin.get();
       
      return 0;
}

void sig_handler(int mySignal)
{
      if(mySignal==SIGINT)
      {
            std::cout<<"i get signal\n";
      }

      pid_t pid;
      pid = wait(NULL);

}

void studyAtExit()
{
      std::cout<<"\nwyswietlam po zakonczeniu\n";
}