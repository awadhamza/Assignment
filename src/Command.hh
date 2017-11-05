#ifndef Command_hh
#define Command_hh

#include "Interface.hh"
#include "CMD.hh"
#include <vector>
#include <iostream>


class CMD;

class Command{
   private:
		std::vector<CMD*> CMDlist;
   public: 
		Command(){};
		~Command();
		int checkConnector(std::string);  //helper function
		std::string cutConnector(std::string);  //helper function
		void splitString(std::string);		//Parser, and fills vector with full and separated commands
		std::vector<CMD*> getVector();	//accessor

};

#endif
