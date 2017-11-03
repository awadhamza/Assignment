# rshell-h-h
rshell-h-h created by GitHub Classroom

Author: Hamza Awad and Huzaifah Simjee

Introduction: 

Assignment 2 will be written in C++. We will be designing the project with two functionalities. First off, we will add functions to allow a user to print a live command prompt line. Second of all, functions will be included that will read in and execute a/multiple command(s) within the same line.


The chosen design style for accomplishing this is composite. This is because it will allow modularity which will make adding additional components simple and will allow smaller objects to be morphed together to make more complex objects.
Thus, as a user, I would like to input multiple commands through an instruction I will write into a program with different connectors that will make each command execute depending on whether or not a previous command has been executed successfully. 

The current state of execution for our rshell seems to retrieve the correct commands in terms of char*s, even when filled with a mix of connectors; however,  when execvp() is called onto a built in command "ls," it appears to not execute and return an error stating that there is no such file or directory called "ls."
