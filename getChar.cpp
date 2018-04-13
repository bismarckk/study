#include <iostream>
#include <string.h>


int main()
{
      char input[100];
      const char delimiter[] = " ";
      char *pwords[20];
      char ch;
      char *remainder , *context;
      int i;

      std::cin.get(ch);
      while (ch!= '\n')
      {
            input[i] +=ch;
            std::cin.get(ch);
      };

      std::cout<<sizeof(input);
      int inputLength = strlen(input);
      char *inputCopy = new char;
      strncpy(inputCopy, input, inputLength);
      std::cout << inputCopy;
      // strtok_r (inputCopy, delimiter, &context);
      //  strtok_r (NULL, delimiter, &context);
      // remainder = context;

}