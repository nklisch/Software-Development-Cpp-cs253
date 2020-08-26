#!/bin/bash

printf "\n   --- TEST 1  --- \n" >>out
g++ -Wall test1giter_begin.cc *.a
if [[ $? -ne 0 ]]
  then
    echo "$0: test1giter_begin compile failed">>err
  else
    ./a.out 1>>out 2>>err
    rm a.out
fi

printf "\n   --- TEST 2 --- \n" >>out
g++ -Wall test2giter_end.cc *.a
if [[ $? -ne 0 ]]
  then
    echo "$0: test2giter_end compile failed \n">>err
  else
    ./a.out 1>>out 2>>err
    rm a.out
fi

printf "\n  --- TEST 3  ---\n" >>out
g++ -Wall test3giter_copyAssign.cc *.a
if [[ $? -ne 0 ]]
  then
    echo "$0: test3giter_copyAssign compile failed \n">>err
  else
    ./a.out 1>>out 2>>err
    rm a.out
fi

printf "\n--- TEST 4 ---\n" >>out
g++ -Wall test4giter_equals.cc *.a
if [[ $? -ne 0 ]]
  then
    echo "$0: test4giter_equals compile failed \n">>err
  else
    ./a.out 1>>out 2>>err
    rm a.out
fi

printf "\n--- TEST 5  ---\n" >>out
g++ -Wall test5giter_increment.cc *.a
if [[ $? -ne 0 ]]
  then
    echo "$0: test5giter_increment compile failed \n">>err
  else
    ./a.out 1>>out 2>>err
    rm a.out
fi

printf "\n--- TEST 6 ---\n" >>out
g++ -Wall test6giter_decrement.cc *.a
if [[ $? -ne 0 ]]
  then
    echo "$0: test6giter_decrement compile failed \n">>err
  else
    ./a.out 1>>out 2>>err
    rm a.out
fi

printf "\n--- TEST 7 ---\n" >>out
g++ -Wall test7giter_getReference.cc *.a
if [[ $? -ne 0 ]]
  then
    echo "$0: test7giter_getReference compile failed \n">>err
  else
    ./a.out 1>>out 2>>err
    rm a.out
fi

printf "\n--- TEST 8 ---\n" >>out
g++ -Wall test8eiter_begin.cc *.a
if [[ $? -ne 0 ]]
  then
    echo "$0: test8eiter_begin compile failed \n">>err
  else
    ./a.out 1>>out 2>>err
    rm a.out
fi

printf "\n--- TEST 9 ---\n" >>out
g++ -Wall test9eiter_end.cc *.a
if [[ $? -ne 0 ]]
  then
    echo "$0: test9eiter_end compile failed \n">>err
  else
    ./a.out 1>>out 2>>err
    rm a.out
fi

printf "\n--- TEST 10 ---\n" >>out
g++ -Wall test10eiter_copyAssign.cc *.a
if [[ $? -ne 0 ]]
  then
    echo "$0: test10eiter_copyAssign compile failed \n">>err
  else
    ./a.out 1>>out 2>>err
    rm a.out
fi

printf "\n--- TEST 11 ---\n" >>out
g++ -Wall test11eiter_equals.cc *.a
if [[ $? -ne 0 ]]
  then
    echo "$0: test11eiter_equals compile failed \n">>err
  else
    ./a.out 1>>out 2>>err
    rm a.out
fi

printf "\n--- TEST 12  ---\n" >>out
g++ -Wall test12eiter_increment.cc *.a
if [[ $? -ne 0 ]]
  then
    echo "$0: test12eiter_increment compile failed \n">>err
  else
    ./a.out 1>>out 2>>err
    rm a.out
fi

printf "\n--- TEST 13  ---\n" >>out
g++ -Wall test13eiter_decrement.cc *.a
if [[ $? -ne 0 ]]
  then
    echo "$0: test13eiter_decrement compile failed \n">>err
  else
    ./a.out 1>>out 2>>err
    rm a.out
fi

printf "\n--- TEST 14  ---\n" >>out
g++ -Wall test14eiter_getReference.cc *.a
if [[ $? -ne 0 ]]
  then
    echo "$0: test14eiter_getReference compile failed \n">>err
  else
    ./a.out 1>>out 2>>err
    rm a.out
fi

printf "\n--- TEST 15 ---\n" >>out
g++ -Wall test15integration_1.cc *.a
if [[ $? -ne 0 ]]
  then
    echo "$0: test15integration_1 compile failed \n">>err
  else
    ./a.out 1>>out 2>>err
    rm a.out
fi

printf "\n--- TEST 16 ---\n" >>out
g++ -Wall test16integration_2.cc *.a
if [[ $? -ne 0 ]]
  then
    echo "$0: test16integration_2 compile failed \n">>err
  else
    ./a.out 1>>out 2>>err
    rm a.out
fi
