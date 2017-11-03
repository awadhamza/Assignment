#ifndef Interface_hh
#define Interface_hh

#include <vector>
using std::vector;

class Interface {
   private:

   public:
      Interface();
      ~Interface();
      void changeConVec(vector<int>);
      void changeCommandVec(vector<vector<char*>>);
      void orchestrate();
};

#endif
