#!/bin/bash

echo 'exit' | ../a.out 	#just exit
echo 'echo A && exit' | ../a.out #A
echo 'echo A || exit' | ../a.out #A, testdone
echo 'echo A; exit' | ../a.out 	#A
echo 'echo A #exit'	| ../a.out 	#A, testdone
