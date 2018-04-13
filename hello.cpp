#include <signal.h>
#include <iostream>
#include<unistd.h>
#include<sys/types.h>
#include "functions.h"

using namespace std;

void print_hello(){
      
      
      cout << "Hello World!"<<endl;
      cout <<sizeof(int)<<endl;
      cout <<sizeof(double)<<endl;
      cout<<sizeof(short)<<endl;
}

void shrink (int *a)
{
      a[1]=0;
}

void sig_handler(int mySignal)
{
      if(mySignal==SIGINT)
      {
            cout<<"i get signal\n";
            _exit(0);            
      }
      
}

void studyAtExit()
{
      std::cout<<"wyswietlam po zakonczeniu\n";
}