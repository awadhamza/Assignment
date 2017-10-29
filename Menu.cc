#include "Menu.hh"


Menu::Menu() : returnCMD("") {}

Menu::~Menu() {}

bool Menu::verifyPrompt(std::string prompt)
{
   
   //I decided that split string will verify as it splits, that way
   // access to the vector is simpler, and it allows menu to simply be a menu.
   CMD::splitString(prompt);
   
   /* I WILL DISCARD BELOW LATER
   for(unsigned i = 0; i < this->CMDList.size(); i++)
   {
      if(Compare CMDList[i] to something and verify it)
      {
         return false;
      }
   }
   */
   return true;

   /* Is there a way to compare system commands with our prompt?
 *    Also, should we split our prompt into strings, and use our vector
 *    in Command class to compare commands with? Because the prompt
 *    could be filled with more than one vector. Or should we even verify
 *    the prompts here?
 */
}

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
