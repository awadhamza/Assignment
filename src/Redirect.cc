#include "Redirect.hh"
#include "Tokenizer.h"

void Redirect::readyVector()
{
	string currCommand;
	Tokenizer splitter(getString());
	vector<string> vectorCopy = getVector();
	
	while((currCommand = splitter.next()) != "")
	{
		
		vectorCopy.push_back(currCommand);
		
	}
}

void Redirect::execute()
{
	execute(getString(), getConnector());
}

void Redirect::execute(string fullCommand, int connector)
{
	readyVector();
	
	vector<string> vectorCopy = getVector();
	
	while(true){
		
		if(vectorCopy.size() >= 3)
		{
			string leftString = vectorCopy.at(vectorCopy.size() - 3);
			string leftConnector = vectorCopy.at(vectorCopy.size() - 2);
			string rightString = vectorCopy.at(vectorCopy.size() - 1);
		} else {
			break;
		}
		if(leftConnector == '|')
		{
			executePipe(leftString, rightString);
		} else if (leftConnector == '>')
		{
			executeG(leftString, rightString);
		} else if (leftConnector == ">>")
		{
			executeGG(leftString, rightString);
		} else if (leftConnector == '<')
		{
			executeL(leftString, rightString);
		}
		
	}
	
}

void executePipe(string command, string secondCommand)
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
		temp.execute();
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
void executeGG(string , string )
{
	
}
void executeG(string , string )
{
	
}
void executeL(string , string )
{
	
}

bool Redirect::is_Group()
{
	return false;
}

void Redirect::setType(string path)
{
	typePath = path;
}

void Redirect::setString(string str)
{
	fullPath = str;
}

string Redirect::getString()
{
	return fullPath;
}

string Redirect::getConnector()
{
	return connector;
}

vector<string> Redirect::getVector()
{
	return separatedPath;
}
