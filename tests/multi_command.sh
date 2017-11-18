#!/bin/bash


echo 'echz THIS SHOULDNT OUTPUT && git status && echo a || ls -a; echo END OF TEST!' | ../a.out
echo 'echo A && echo B' | ../a.out
echo 'echo A || echo B' | ../a.out
echo 'echo A; echo B' | ../a.out
echo 'ls -j && echo A' | ../a.out
echo 'ls -j || echo A' | ../a.out
echo 'ls -j; echo A' | ../a.out
echo 'cal 4 2009 && echo This is a date || echo b' | ../a.out
echo 'echo "A || B" && echo PrintHere' | ../a.out
echo 'echo "A && B" || echo PrintHERE' | ../a.out
echo 'pwd fileNotExist || echo Yes && echo "Temp || "' | ../a.out
