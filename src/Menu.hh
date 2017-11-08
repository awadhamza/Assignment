#include <iostream>
#include "Command.hh"

#ifndef Menu_hh
#define Menu_hh

class Menu {
   private:
      std::string returnCMD;
   
   public:
      Menu();
   
      ~Menu();
   
      //Runs the entire program. The core of the funciton is to display
      // a running command prompt and receive the prompt.
      void getPrompt();
      
      
      //Returns returnCMD such that it is protected and
      // can be accessed in different classes as necessary.
      std::string accessString();
};

#endif
