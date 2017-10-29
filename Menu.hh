#include <iostream>
#include "Command.hh"

#ifndef Menu_hh
#define Menu_hh

class Menu {
   private:
      string returnCMD;
   
   public:
      Menu();
   
      ~Menu();
   
      //Runs the entire program. The core of the funciton is to display
      // a running command prompt and receive the prompt. This function
      // will then signal Command's child, CMD class, to access it and 
      // split strings of the prompt entered in returnCMD.
      void getPrompt();
      
      //This function will be used in getPrompt() to analyze whether a 
      // command(s) were entered in properly. If not, getPrompt() will 
      // repeat.
      bool verifyPrompt(string );
      
      //Returns returnCMD such that it is protected and
      // can be accessed in different classes as necessary.
      string accessString();
};

#endif
