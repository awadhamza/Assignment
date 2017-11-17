#ifndef GROUP_HH
#define GROUP_HH

#include "CMD.hh"
#include <vector>
#include <iostream>

using std::cout;
using std::cin;
using std::string;
using std::vector;

class Group : public Base {
	public:
		Group() : Base() {}
		Group(string, int);
		void makeGroup(string);
		void execute(string, int);
		bool is_Group();
		
	private:
		vector<Base*> Grouplist;
};

#endif
