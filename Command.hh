#ifndef Command_hh
#define Command_hh

#include "Interface.hh"
#include "Tokenizer.h"
#include <vector>
#include <iostream>

using std::string;
using std::vector;

class Command{
   private:
		vector<vector<char*>> CMDVec;
		vector<int> connectVec;
   public:
        Command(){};
        ~Command(){};
        int checkConnector(std::string);
        std::string cutConnector(std::string);
        void splitString(string);
        vector<int> getConVec();
		vector<vector<char*>> getCommandVec();
};

#endif

