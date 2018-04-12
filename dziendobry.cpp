#include<iostream>
#include<unistd.h>

int main(int argc, char *argv[]) 
{
      
      std::cout<<"\nDziendobry\n";
      std::cout<<getppid()<<std::endl;
      for (int i =1;i<argc;i++){
            std::cout<<argv[i]<<std::endl;
            argv[i]="psss!!!";
      }
}
