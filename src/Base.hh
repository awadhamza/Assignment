#ifndef BASE_HH
#define BASE_HH

#include <iostream>

class Base
{
	public:
		virtual void execute(std::string, int) = 0;
		void changeConnector(int);
		int getConnector();
		int getDone();
		void setDone(int);
		std::string getInstruction();
		virtual bool is_Group() = 0;
	
	protected:
		int connector;
		int done;
		std::string instruction;
};

#endif
