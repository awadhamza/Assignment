output: Base.o CMD.o Command.o Execute.o Group.o Interface.o Menu.o test.o Tokenizer.o
	g++ Base.o CMD.o Command.o Execute.o Group.o Interface.o Menu.o test.o Tokenizer.o -o output
	
	
test.o: src/test.cpp
	g++ -c src/test.cpp -std=c++11

Base.o: src/Base.cc src/Base.hh
	g++ -c src/Base.cc -std=c++11

CMD.o: src/CMD.cc src/CMD.hh
	g++ -c src/CMD.cc -std=c++11

Command.o: src/Command.cc src/Command.hh
	g++ -c src/Command.cc -std=c++11

Execute.o: src/Execute.cc src/Execute.hh
	g++ -c src/Execute.cc -std=c++11

Group.o: src/Group.cc src/Group.hh
	g++ -c src/Group.cc -std=c++11

Interface.o: src/Interface.cc src/Interface.hh
	g++ -c src/Interface.cc -std=c++11

Menu.o: src/Menu.cc src/Menu.hh
	g++ -c src/Menu.cc -std=c++11

Tokenizer.o: src/Tokenizer.cpp src/Tokenizer.h
	g++ -c src/Tokenizer.cpp -std=c++11

clean:
	rm *.o rshell

