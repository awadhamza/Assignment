#ifndef Command_hh
#define Command_hh

#include "Interface.hh"
#include "Tokenizer.h"
#include "CMD.hh"
#include <vector>
#include <iostream>

using std::string;
using std::vector;

class Command{
   private:
		vector<CMD*> CMDlist;
   public:
        Command(){};
        ~Command();
        int checkConnector(std::string);
        std::string cutConnector(std::string);
        void splitString(string);
        vector<CMD*> getVector();
};

#endif

