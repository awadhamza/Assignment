#ifndef Interface_hh
#define Interface_hh

#include "Menu.hh"
#include "Execute.hh"

class Interface {
   private:
      vector<int> connectors;
      vector<vector<char*>> commands;     
   public:
      Interface();
      ~Interface();
      void changeConVec(vector<int>);
      void changeCommandVec(vector<vector<char*>>);
      void orchestrate();
};

#endif
