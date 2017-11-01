#include "Menu.hh"


Menu::Menu() : returnCMD("") {}

Menu::~Menu() {}

void Menu::getPrompt()
{
   std::string prompt;
   bool validPrompt = false;
   
   while(!validPrompt)
   {
      std::cout << "$ ";
      getline(std::cin, prompt);
   
      validPrompt = verifyPrompt(prompt); 
   }
   
   return;
/* As of now, CMDList should be filled with valid and split commands. 
 * The user will wait till they execute, if at all, then this prompt will 
 * be called again.
 */
}

std::string Menu::accessString()
{
   return returnCMD;
}
