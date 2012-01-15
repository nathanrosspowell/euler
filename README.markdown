# PROJECT EULER
I have been attempting the Project Euler challenges as a learning exercise - 
primarily to enhance my problem solving skills
and secondly to aid in the learning of new programming languages.

## Languages
* C plus plus
* Python
* Haskell

## Executing
This repro is tested against these versions
    
* Ubuntu 10.10
* Python 2.6.6
* GCC 4.4.5
* Glasgow Compiler 6.12.1

Completed problems will be ran by the testing utility and double checked against the correct answer

    testing/runall.py

To filter the testing add a language (or list of them) and a problem number (or list of them)

    python testing/runspecific.py cpp 1
    python testing/runspecific.py cpp 1 2 99 142
    python testing/runspecific.py cpp haskell 1
    python testing/runspecific.py cpp haskell 42 69

