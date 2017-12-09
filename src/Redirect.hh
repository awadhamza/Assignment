#ifndef REDIRECT_HH
#define REDIRECT_HH

#include "Base.hh"

#include <vector>
#include <iostream>

using std::cout;
using std::cin;
using std::string;
using std::vector;

class Redirect : public Base {
	private:
		string fullPath;
		string typePath;
	
	public:
		
		Redirect() : Base(), fullPath(""), typePath("") {}
		Redirect(string path, string type) : Base(), fullPath(path), typePath(type) {}
		~Redirect();
		string findNextDirection(string );
		void execute();
		void execute(string , int );
		bool is_Group();
		void setType(string );
		void setString(string );
		string getString();
		string getType();
		
};

#endif
