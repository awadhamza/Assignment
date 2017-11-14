#ifndef Interface_hh
#define Interface_hh

<<<<<<< HEAD:src/Interface.hh
#include "Menu.hh"
#include "Execute.hh"
=======
#include <vector>
using std::vector;
>>>>>>> 1e26fa27506eab6ebae24c8f64719c1f37984368:src/Interface.hh

class Interface {
   private:

   public:
      Interface();
      ~Interface();
      void changeConVec(vector<int>);
      void changeCommandVec(vector<vector<char*> >);
      void orchestrate();
};

#endif
