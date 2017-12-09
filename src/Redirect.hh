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
		vector<string> separatedPath;
	
	public:
		
		Redirect() : Base(), fullPath(""), typePath(""), separatedPath(0) {}
		Redirect(string path, string type) : Base(), fullPath(path), typePath(type), separatedPath(0) {}
		~Redirect();
		string findNextDirection(string );
		string findNextString(string );
		void readyVector();
		void execute(string , int );
		bool is_Group();
		void setType(string );
		void setString(string );
		string getString();
		string getType();
		
};

#endif
