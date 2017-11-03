#ifndef Command_hh
#define Command_hh

#include "Interface.hh"
#include "Tokenizer.hh"
#include <vector>

class Command{
   private:
   public:
        Command(){};
        ~Command(){};
        int checkConnector(std::string);
        std::string cutConnector(std::string);
        void splitString(string);
};

#endif

