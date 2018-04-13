#include <iostream>
//#include <dlfnc.h>
#include<sys/types.h>
#include<sys/times.h>
#include<unistd.h>
#include <signal.h>
#include<stdlib.h>
#include "functions.h"
using namespace std;


int main(int argc, char *argv[]){

      pid_t pidChild, pidChild1;
      tms buf;
      clock_t processtime;
      processtime = times(&buf);

      
      ///////funkcja execve... otwiera program ktory dziedziczy pid juz nie powraca do funkcji
      char *newargv[] = { NULL, "hello", "world", NULL };
      char *newenviron[] = { NULL };
      cout<<argv[0]<<endl;
        
      
      // int *i = new int[5];
      // print_hello();
      // cout<<endl;
      // cout << "The factorial of 5 is " << factorial(5) << endl;
      // *i = 3;
      // i[1]=1;
      // cout<<i[1]<<endl;
      // shrink(i);
      // cout<<i[1]<<*i<<i[0]<<endl;
      // delete i;



      // ###ilosc taktow zegara podzielona na ilosc taktow w sekundzie ale nic nie zwraca
      for (int i =0, a=0;i<100000;i++){a+=i;}
      processtime = times(&buf);
      cout<<buf.tms_stime<<endl;
      cout<<buf.tms_utime<<endl;
      cout <<"System time w s: "<<(double) buf.tms_stime/sysconf(_SC_CLK_TCK)<<endl;
      cout <<"User time w s: " <<(double) buf.tms_utime/sysconf(_SC_CLK_TCK)<<endl;    
      cout<<"\nParent pid przed fork "<<getpid()<<endl<<endl;


      if(signal(SIGINT, sig_handler)==SIG_ERR);
      signal(SIGCHLD,SIG_IGN);
            
      //sleep(5);
      
      
      // ###fork wykonuje parent i rozpoczyna child a vfork zawiesza parent i czeka az child zostanie zakonczony i dopiero konczy parent
      cout<<"tu zaczyna sie vfork()\n";
      pidChild = vfork();    
      
      if(pidChild == 0)
      {            
            cout<<"\nchild process \"0\"\n";
            cout<<"proces biezacy "<<getpid()<<endl;
            cout<<"proces macierzysty "<<getppid()<<endl;

            
            cout<<getppid()<<std::endl;
            execve(argv[1], newargv, newenviron);  
            
            cout<<"\ntu zaczyna sie fork()\n";
            pidChild1 = fork();
                 
            if(pidChild1 == 0)
            {            
                  cout<<"\nchild process \"1\"\n";
                  cout<<"proces biezacy "<<getpid()<<endl;
                  cout<<"proces macierzysty "<<getppid()<<endl;
                  
                  atexit(studyAtExit);
                  exit(0);         
                        
            }
            else if(pidChild1 < 0)
            {  
                  cout<<"failed child process\n";  
            }
            else if (pidChild1 > 0)
            {                  
                  cout<<"\nParent process \"1\"\n";
                  cout<<"Child Pid  "<<pidChild1<<endl;
                  cout<<"proces biezacy pid "<<getpid()<<endl;
                  cout<<"proces macierzysty pid "<<getppid()<<endl;                   
            }              
            
            _exit(0);    
      }
      else if(pidChild < 0)
      {  
            cout<<"failed child process\n";  
      }
      else if (pidChild > 0)
      {                  
            cout<<"\nParent process \"0\"\n";
            cout<<"Child Pid  "<<pidChild<<endl;
            cout<<"proces biezacy pid "<<getpid()<<endl;
            cout<<"proces macierzysty bash tu akuart "<<getppid()<<endl;                   
      }
      
      
      
      return 0;
}