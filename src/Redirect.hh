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
		int connector;
		vector<string> separatedPath;
	
	public:
		
		Redirect() : Base(), fullPath(""), connector(888), separatedPath(0) {}
		Redirect(string path, int con) : Base(), fullPath(path), connector(con), separatedPath(0) {}
		~Redirect();
		void readyVector();
		void execute();
		void execute(string , int );
		void executePipe(string , string );
		void executeGG(string , string );
		void executeG(string , string );
		void executeL(string , string );
		bool is_Group();
		void setString(string );
		string getString();
		string getConnector();
		vector<string> getVector();
		bool contains( string cmd, char c );
		
};

#endif
