#ifndef Command_hh
#define Command_hh

#include "Interface.hh"
#include "CMD.hh"
#include "Tokenizer.hh"
#include <vector>

class CMD;

class Command{
   private:  
      std::vector<CMD*> CMDlist;
   public: 
     	Command(){};
      	~Command(){};
	int checkConnector(std::string);
	std::string cutConnector(std::string);
      	void splitString(string);      
};

#endif
