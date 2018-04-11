
#include <iostream>
//#include <dlfnc.h>
#include<sys/types.h>
#include<unistd.h>
#include "functions.h"
using namespace std;


int main(){

      //pid_t pid1=0;
      int *i = new int[5];

      print_hello();
      cout<<endl;
      cout << "The factorial of 5 is " << factorial(5) << endl;
      *i = 3;
      i[1]=1;
      cout<<i[1]<<endl;
      shrink(i);
      cout<<i[1]<<*i<<i[0]<<endl;
      delete i;
      // pid1 = fork();
      // cout<<getpid()<<pid1<<endl;
      // cout<<"czy to bedzie to? "<<pid1<<endl;
      //pid1 =fork();
      //cout<<"czy to bedzie to? "<<pid1<<endl;      
      cin >> i[2];

      pid_t pid1, pid2, pid3;
      pid1=0, pid2=0, pid3=0;
      pid1= fork(); 
      cout<<"pid 1: "<<pid1<<endl;
      
      if(pid1==0){
            pid2=fork();
        pid3=fork(); 
        cout<<"pid 3: "<<pid3<<endl;
      } else {
            pid3=fork(); 
            cout<<"pid 3: "<<pid3<<endl;
            if(pid3==0) {
                  pid2=fork(); 
            }
            
            if((pid1 == 0)&&(pid2 == 0))
                 cout <<pid1<<" level1\n";
            
            if(pid1 !=0)
                  cout <<pid1<<" level2\n";
            
            if(pid2 !=0)
                  cout <<pid2<<" level3\n";
            
            if(pid3 !=0)
                  cout <<pid3<<" level4\n";      
    
      }
      
      return 0;
}