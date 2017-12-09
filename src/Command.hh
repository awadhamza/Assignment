#ifndef Command_hh
#define Command_hh

#include "Interface.hh"
#include "Tokenizer.h"
#include "CMD.hh"
#include "Group.hh"
#inlcude "Redirect.hh"
#include <vector>
#include <iostream>


class CMD;

class Command{
   private:
		std::vector<Base*> commandList;
   public: 
		Command(){};
		~Command();
		int checkConnector(std::string);  //helper function
		std::string cutConnector(std::string);  //helper function
		void splitString(std::string);		//Parser, and fills vector with full and separated commands
		vector<Base*> getVector();	//accessor
		void fixTouchingConnectors(string& instruction);
		bool fixParen(Tokenizer& splitter, string& currCommand, string& basket, int& connection, Base* temp);
		bool fixQuote(Tokenizer& splitter, string& currCommand, string& basket, int& connection, Base* temp);
};

#endif
