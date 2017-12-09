#include "Redirect.hh"
#include "Tokenizer.h"
#include <unistd.h>		
#include <stdio.h>		
#include <stdlib.h>
#include <iostream>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <cstdlib>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <signal.h>
#include <iostream>
#include <stdlib.h>
#include <sys/wait.h>
#include <fstream> 

const int MAX_ARGS = 64;

void Redirect::readyVector()
{
	string currCommand;
	Tokenizer splitter(getString());
	vector<string> vectorCopy = getVector();
	string basket = "";
	
	while((currCommand = splitter.next()) != "")
	{
		
		if(currCommand == "|" || currCommand == ">" || currCommand == "<"){
			vectorCopy.push_back(basket);
			vectorCopy.push_back(currCommand);
			basket = "";
		}
		else if (basket.size() != 0){
			basket += " " + currCommand;
		}
		else
		{
			basket += currCommand;
		}
		
	}
}

void Redirect::execute()
{
	execute(fullPath, connector);
}

void Redirect::execute(string fullCommand, int connector)
{
	readyVector();
	
	string leftString;
	string leftConnector;
	string rightString;
	
	vector<string> vectorCopy = getVector();
	
	while(true){
		
		if(vectorCopy.size() >= 3)
		{
			leftString = vectorCopy.at(vectorCopy.size() - 3);
			leftConnector = vectorCopy.at(vectorCopy.size() - 2);
			rightString = vectorCopy.at(vectorCopy.size() - 1);
		} else {
			break;
		}
		if(leftConnector == "|")
		{
			executePipe(leftString, rightString);
		} else if (leftConnector == ">")
		{
			executeG(leftString, rightString);
		} else if (leftConnector == ">>")
		{
			executeGG(leftString, rightString);
		} else if (leftConnector == "<")
		{
			executeL(leftString, rightString);
		}
		
	}
	
}

void Redirect::executePipe(string command, string secondCommand)
{
	string completeCommand = command;
  string completeCommand1 = secondCommand;
  char splitCommand[1024];
  char *executables[1024];
  char splitCommand1[1024];
  char *executables1[1024];
  int charSize = completeCommand.size();
  int charSize1 = completeCommand1.size();
  char* addLetter = NULL;
  int i = 0;
  int executablesIndex = 0;
  char* addLetter1 = NULL;
  int i1 = 0;
  int executablesIndex1 = 0;
  
  for (unsigned int j = 0; j < completeCommand.size(); j++){
    splitCommand[j] = completeCommand[j];
  }
  
  splitCommand[charSize] = '\0';
  
  addLetter = strtok(splitCommand, " " );
  
  while(addLetter != NULL){
    executables[i++] = addLetter;
    addLetter = strtok(NULL, " ");
    executablesIndex++;
  }
  
  for (unsigned int j1 = 0; j1 < completeCommand1.size(); j1++){
    splitCommand1[j1] = completeCommand1[j1];
  }
  
  splitCommand1[charSize1] = '\0';
  
     addLetter1 = strtok(splitCommand1, " ");    
         
           while(addLetter1 != NULL){
               executables1[i1++] = addLetter1;
               addLetter1 = strtok(NULL, " ");
               executablesIndex1++;
           }

    int     nbytes, ret, size, length, Descriptor1, Descriptor2, saveSTDIN, saveSTDOUT, writenum    ;
    int fd[2];

    pid_t   childpid;

string line, cmd1, cmd2;
char* input[MAX_ARGS];
int FD[2];

pipe(FD);
        
pid_t pid = fork();
if( pid == 0 ){
        close(FD[0]); //close pipe output
        dup2(FD[1], 1); //copy pipe input to stdout
	
	if(contains(completeCommand, '|') || contains(completeCommand, '<') || contains(completeCommand, '>')){
		Redirect* temp = new Redirect(completeCommand, 0);
		temp->execute();
	}
	else{
		if(execvp(splitCommand, executables) == -1){
             	 	cout << "FAILED" << endl;
            	}
        }
        }
 else 
        {
            close(FD[1]); //close pipe input
            dup2(FD[0], 0); //copy pipe output to stdin
	  if(execvp(splitCommand1, executables1)){
              cout << "FAILED" << endl;
            }
        }
}
void Redirect::executeGG(string command, string file)
{
	string completeCommand = command;
  char splitCommand[1024];
  char *executables[1024];
  int charSize = completeCommand.size();
  char* addLetter = NULL;
  int i = 0;
  int executablesIndex = 0;
  
  for (unsigned int j = 0; j < completeCommand.size(); j++){
    splitCommand[j] = completeCommand[j];
  }
  
  splitCommand[charSize] = '\0';
  
  addLetter = strtok(splitCommand, " " );
  
  while(addLetter != NULL){
    executables[i++] = addLetter;
    addLetter = strtok(NULL, " ");
    executablesIndex++;
  }
    
    
    int     nbytes, ret, size, length, Descriptor1, Descriptor2, saveSTDIN, saveSTDOUT, writenum    ;
    int fd[2];
    string filename = completeCommand.substr(4, completeCommand.size() - 4);
    string newFile = file;
    pid_t   childpid;
    ifstream is;
    
    ifstream ifs(newFile);
      string str((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
    
    
    const char* pathFileName = filename.c_str();
    const char* pathNewFile = newFile.c_str();
    
    is.open (pathFileName, ios::binary );
    is.seekg (0, ios::end);
    length = is.tellg();
    
    char    readbuffer[length+1];
    
    
    saveSTDIN = dup(0);   
    saveSTDOUT = dup(1);   
    close(0);
    close(1);
    
    Descriptor1 = open(pathFileName, O_RDONLY);
    if (Descriptor1 < 0)
    {
        printf("FIRST: Can’t read file using file\n");
        exit (1);
    }
    
    Descriptor2 = open(pathNewFile, O_CREAT | O_WRONLY | O_APPEND, 0600);
    if (Descriptor2 < 0)
    {
        printf("SECOND: Can’t read file using file\n");
        exit (1);
    }
    
    ret = pipe(fd);
    if(ret == -1){
        perror("pipe");
        exit(1);
    }
    
    childpid = fork();
    
  if( childpid == 0) {
      execvp(splitCommand, executables);
    
  } else if ( childpid > 0 ) { //parent case
  } else {
      cout << "This is an error" << endl;
  }
  
    dup2(saveSTDIN, 0);
    dup2(saveSTDOUT, 1);
    close(Descriptor1);
    close(Descriptor2);
}
void Redirect::executeG(string command, string file)
{
	  string completeCommand = command;
  char splitCommand[1024];
  char *executables[1024];
  int charSize = completeCommand.size();
  char* addLetter = NULL;
  int i = 0;
  int executablesIndex = 0;
  
  for (unsigned int j = 0; j < completeCommand.size(); j++){
    splitCommand[j] = completeCommand[j];
  }
  
  splitCommand[charSize] = '\0';
  
  addLetter = strtok(splitCommand, " " );
  
  while(addLetter != NULL){
    executables[i++] = addLetter;
    addLetter = strtok(NULL, " ");
    executablesIndex++;
  }
    
    
    int     nbytes, ret, size, length, Descriptor1, Descriptor2, saveSTDIN, saveSTDOUT, writenum    ;
    int fd[2];
    string filename = completeCommand.substr(4, completeCommand.size() - 4);
    string newFile = file;
    pid_t   childpid;
    ifstream is;
    
    const char* pathFileName = filename.c_str();
    const char* pathNewFile = newFile.c_str();
    
    is.open (pathFileName, ios::binary );
    is.seekg (0, ios::end);
    length = is.tellg();
    
    char    readbuffer[length+1];
    
    
    saveSTDIN = dup(0); 
    saveSTDOUT = dup(1);
    close(0);
    close(1);
    
    Descriptor1 = open(pathFileName, O_RDONLY);
    if (Descriptor1 < 0)
    {
        printf("FIRST: Can’t read file using file\n");
        exit (1);
    }
    
    Descriptor2 = open(pathNewFile, O_CREAT | O_WRONLY, 0600);
    if (Descriptor2 < 0)
    {
        printf("SECOND: Can’t read file using file\n");
        exit (1);
    }
    
    ret = pipe(fd);
    if(ret == -1){
        perror("pipe");
        exit(1);
    }
    
    childpid = fork();
    
  if( childpid == 0) {
      execvp(splitCommand, executables);
    
  } else if ( childpid > 0 ) { //parent case
  } else {
      cout << "This is an error" << endl;
  }
  
    dup2(saveSTDIN, 0);
    dup2(saveSTDOUT, 1);
    close(Descriptor1);
    close(Descriptor2);
}
void Redirect::executeL(string , string )
{
	
}

bool Redirect::is_Group()
{
	return false;
}

void Redirect::setString(string str)
{
	fullPath = str;
}

string Redirect::getString()
{
	return fullPath;
}

int Redirect::getConnector()
{
	return connector;
}

vector<string> Redirect::getVector()
{
	return separatedPath;
}

bool Redirect::contains( string cmd, char c )
{
  size_t pos = cmd.find( c );
  return pos != string::npos;
}
