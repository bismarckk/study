#include <iostream>
#include "functions.h"


void print_hello(){
      
      using namespace std;
      cout << "Hello World!"<<endl;
      cout <<sizeof(int)<<endl;
      cout <<sizeof(double)<<endl;
      cout<<sizeof(short)<<endl;
}

void shrink (int *a)
{
      a[1]=0;
}