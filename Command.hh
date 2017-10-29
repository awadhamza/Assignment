#ifndef Command_hh
#define Command_hh

#include "Interface.hh"
#include <vector>

class Command : public Interface {
   private:
      
   public: 
      Command(){};
      ~Command(){};
      
      std::vector<CMD> CMDList;
      
      void execute() = 0;
};

#endif
