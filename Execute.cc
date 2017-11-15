#include "src/Execute.hh"
#include <unistd.h>		//Grants executeable ability
#include <stdio.h>		//Grants error checking output
#include <stdlib.h>
#include <iostream>
#include <sys/wait.h>
#include <sys/types.h>
#include "src/Tokenizer.h"
#include <string.h>


using namespace std;

using namespace std;

using namespace std;

/*
 * Note to self
 * 
	string str = "string";
	char *cstr = new char[str.length() + 1];
	strcpy(cstr, str.c_str());
	
	// do stuff
	delete [] cstr;
 *  
 */

Execute::Execute()
{
}

Execute::~Execute() 
{

}

void Execute::doThis(char[] , char*[])
{
	
	
	
}

void Execute::execute(std::vector<CMD*> CMDlist)
{
	int vec_index = 0;
	int success = 0;

	//for( unsigned i = 0; i < CMDlist.size(); i++)
	//{
	//	cout << CMDlist.at(i)->getInstruction() << " " << i << " ===== ";
	//}
	//cout << endl;
	for( vec_index; vec_index < CMDlist.size(); ++vec_index )
	{
		int temp = 0;	
		
		std::string currCommand = CMDlist.at(vec_index)->getInstruction();
		char** argz;
		
		string completeCommand = CMDlist.at(vec_index) -> getInstruction();
		char splitCommand[1024];
  		char *executables[1024];
  		int charSize = completeCommand.size();
  		char* addLetter = NULL;
 		int i = 0;
  		int executablesIndex = 0;
  
  		for (unsigned int j = 0; j < completeCommand.size(); j++){
    			splitCommand[j] = completeCommand[j];
  		}
  		
  		splitCommand[charSize + 1] = '0';
  
  		addLetter = strtok(splitCommand, " " );
  
  		while(addLetter != NULL){
    			executables[i++] = addLetter;
    			addLetter = strtok(NULL, " ");
   			executablesIndex++;
  		}

		pid_t pid = fork();
		
		if(pid < 0) //fork failed
		{
			std::cout << "Fork error. Quitting Program." << std::endl;

			exit(-1);
			
		} else if(pid == 0)//child process
		{
					
			
			//for(unsigned i = 0; i < CMDlist.size(); ++i){
			//	cout << CMDlist.size() << endl;
			//	cout << CMDlist.at(i)->getInstruction() << endl;
			//	CMDlist.at(i)->setDone(45);
			//}
			
			//cout << "this is it: " << first << endl;
			//execvp(splitCommand, executables);
			
			int indexSave = vec_index; //Incase we need it
			
			if(CMDlist.at(vec_index)->getDone() == 0)	//-------------------------------If this command is unchecked
			{
				if(CMDlist.at(vec_index)->getConnector() == 3)	//If "&&" connector
				{
					
					CMDlist.at(vec_index)->setDone(2); //Setting to true if it will work
					execvp(splitCommand, executables); //If success, parent should iterate to the next one
					
					//If failed, will set done to 1
					CMDlist.at(vec_index)->setDone(1); //Setting to false since failed
					while(CMDlist.at(vec_index)->getConnector() == 3)
					{
						CMDlist.at(vec_index)->setDone(1);
						vec_index++;
					}
					CMDlist.at(vec_index)->setDone(1);
					vec_index++;	//Offset
					exit(0);
					
				} else if (CMDlist.at(vec_index)->getConnector() == 2)	//If "||" connector
				{
					cout << "ITS DOING IT" << endl;
					CMDlist.at(vec_index)->setDone(2); //Setting to true if it will work
					while(CMDlist.at(vec_index)->getConnector() == 2)
					{
						CMDlist.at(vec_index)->setDone(2);
						vec_index++;
					}
					CMDlist.at(vec_index)->setDone(2);
					vec_index++;	//Offset
					
					cout << CMDlist.at(indexSave)->getDone() << " is the done status for the current CMD" << endl;
					
					execvp(splitCommand, executables); //If success, parent should iterate to the next one
					
					//If failed, will set done to 1
					CMDlist.at(vec_index)->setDone(1); //Setting to false since failed and parent should go to next
					vec_index = indexSave;
					while(CMDlist.at(vec_index)->getConnector() == 2)
					{
						CMDlist.at(vec_index)->setDone(0);
						vec_index++;
					}
					cout << "ITS DONE" << endl;
					exit(0);
					
				} else { //if ';' or ''
					
					CMDlist.at(vec_index)->setDone(2);	//Success
					execvp(splitCommand, executables);
					
					CMDlist.at(vec_index)->setDone(1);	//Failure
					exit(0);
					
				}
			} else if (CMDlist.at(vec_index)->getDone() == 1) //------------------------If this command had failed
			{
				if(CMDlist.at(vec_index)->getConnector() == 3)
				{
					
					while(CMDlist.at(vec_index)->getConnector() == 3){
						vec_index++;
					}
					
				} else if (CMDlist.at(vec_index)->getConnector() == 2){
					//Don't offset or do anything, the forloop will iterate
				} else {
					//Don't offset or do anything, the forloop will iterate
				}
			} else if (CMDlist.at(vec_index)->getDone() == 2) //-----------------------If this command had succeeded
			{
				if(CMDlist.at(vec_index)->getConnector() == 3)
				{
					
					//Don't offset or do anything, the forloop will iterate
					
				} else if (CMDlist.at(vec_index)->getConnector() == 2){
					
					while(CMDlist.at(vec_index)->getConnector() == 3){
						vec_index++;
					}
					
				} else {
					//Don't offset or do anything, the forloop will iterate
				}
			}
			
			
			
			
			
			
			//==================================== Last Working Version
			/*
			
			
			int temp = vec_index;
			
			if(CMDlist.at(vec_index)->getConnector() == 2)	//OR connector
			{
				perror("invalid command");
				while(CMDlist.at(vec_index)->getConnector() == 2)
				{
					vec_index++;
				}
				success++;
				
				if(execvp(splitCommand, executables) == -1)
				{
					vec_index = temp + 1;
					success--;
				}
			} else if (CMDlist.at(vec_index)->getConnector() == 3)	//AND connector
			{
				success++;
				vec_index++;
				if(execvp(splitCommand, executables) == -1)
				{
					perror("invalid command");
					vec_index--;
					while(CMDlist.at(vec_index)->getConnector() == 3)
					{
						vec_index++;
					}
					
					success--;
				}
			} else {	// ';' or newline
				vec_index++;
				success++;
				
				if(execvp(splitCommand, executables) == -1)
				{
					perror("invalid command");
					success--;
				}
			}
			
			while(success){
				cout << success << " ";
				wait(0);
				success--;
			}
			cout << endl;
			*/
			//=================================================
			
			
			
		} else //parent process
		{
			for(unsigned i = 0; i < CMDlist.size() - 1; i++)
			{
				wait(NULL);
			}
		}
	}
	
	
	
	for(unsigned i = 0; i < CMDlist.size(); ++i){
		cout << CMDlist.at(i)->getDone() << endl;
	}
	
		/*
		for(int i = 0; i < argsChar.length(); i++){
			cout << "DIS TING " << args[i] << endl;
		}
		*/
		
		/*
		string argsChar = (CMDlist.at(vec_index)->getInstruction());
		
		vector<char> VectoChar(argsChar.length() + 1);
		strcpy(&VectoChar[0], argsChar.c_str());
		char argsVecTemp = VectoChar[0];
		argsVecTemp[static_cast<int>(argsChar.length())] = '\0';
		char* argsVec = &argsVecTemp;
		const char* first = &argsVec[0];
		char* const* args = &argsVec;
		*/
		
		
		//char* args[2];
		//args[0] = (char*)currCommand.c_str();
		//args[1] = 0;
			/*
		if(pid == 0) //Child process
		{
			success++;
			if(CMDlist.at(vec_index)->getConnector() == 3)
			{
<<<<<<< HEAD
<<<<<<< HEAD
				success++;
				vec_index++;
				
				if(execvp(argz[0], argz) < 0){
					perror("exec failed");
=======
=======
>>>>>>> 1e26fa27506eab6ebae24c8f64719c1f37984368
				if( execvp(first, args) == -1 ) // if a command with a && failed
				{			
					success--;		
					perror("exec");
>>>>>>> 1e26fa27506eab6ebae24c8f64719c1f37984368
					while(CMDlist.at(vec_index)->getConnector() == 3)
					{
						vec_index++;
					}
					//vec_index++; //for offset
					success--;
					
<<<<<<< HEAD
<<<<<<< HEAD
				}
			}
			else if (CMDlist.at(vec_index)->getConnector() == 2)
			{
				temp = vec_index;
				while(CMDlist.at(vec_index)->getConnector() == 2)
				{
					vec_index++;
				}
				//vec_index++; //for offset
				success++;
				
				if(execvp(argz[0], argz) < 0)
=======
				}		
			}
			else if (CMDlist.at(vec_index)->getConnector() == 2)
			{
=======
				}		
			}
			else if (CMDlist.at(vec_index)->getConnector() == 2)
			{
>>>>>>> 1e26fa27506eab6ebae24c8f64719c1f37984368
				int tempVecIndex = vec_index;
				
				while(CMDlist.at(vec_index)->getConnector() == 2)
					{
						vec_index++;
					}
				if( execvp(first, args) == -1 ) // if a command with a && failed
				{	
					success--;		
					perror("exec");
					vec_index = tempVecIndex + 1;
					
				}	
			}
			else if (CMDlist.at(vec_index)->getConnector() == 1)
			{
				if( execvp(first, args) == -1 )
<<<<<<< HEAD
>>>>>>> 1e26fa27506eab6ebae24c8f64719c1f37984368
=======
>>>>>>> 1e26fa27506eab6ebae24c8f64719c1f37984368
				{
					perror("exec failure");
					success--;
					vec_index = temp + 1;
				}
				
			}
			else 
			{
<<<<<<< HEAD
<<<<<<< HEAD
				vec_index++;
				success++;
				
				if(execvp(argz[0], argz) < 0)
=======
				if( execvp(first, args) == -1 )
>>>>>>> 1e26fa27506eab6ebae24c8f64719c1f37984368
=======
				if( execvp(first, args) == -1 )
>>>>>>> 1e26fa27506eab6ebae24c8f64719c1f37984368
				{
					perror("exec failure");
					success;
				}
			}
			
		}					
	} 
		if (getpid() > 0)	//Parent's block
		{
			for(unsigned i = 0; i < success; ++i)
			{
				wait(0);
			}
			wait(0);
		} 
		else if(getpid() < 0)	//Fork failed
		{
			std::cout << "Fork error. Quitting Program." << std::endl;
			
			exit(-1);
			
		}
	
	*/
	
	return;
	
}
