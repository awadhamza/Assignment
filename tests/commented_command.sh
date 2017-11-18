#!/bin/bash

echo 'echo A #echo B' | ../a.out
echo 'echo A #&& echo B' | ../a.out
echo 'echo "Testing comments inside # Should Print Me"' | ../a.out
echo 'echo A && echo B #&& echo C' | ../a.out
echo 'echo A #; echo B' | ../a.out
echo 'echo A ##### echo B' | ../a.out
echo 'ls #-a' | ../a.out
echo 'echo "#"' | ../a.out
echo 'echo #' | ../a.out
echo 'cal #9 2001' | ../a.out
