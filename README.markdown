# PROJECT EULER
<img src="http://projecteuler.net/profile/nathanrosspowell.png" />

I have been attempting the Project Euler challenges as a learning exercise - 
primarily to enhance my problem solving skills
and secondly to aid in the learning of new programming languages.

## Languages
Currently solutions are presented in

* C++
* Python
* Haskell
* D
* Erlang

## Installing
This repo is tested against these versions

* Ubuntu 12.04 & 11.10
* Python 2.6.6
* GCC 4.4.5
* Clang 2.9
* Glasgow Compiler 6.12.1
* GDC
* Erlang R14B04

Call the bash script `install.bash` to get the needed software.

## Executing
Completed problems will be ran by the testing utility and double checked against the correct answer

    python testing/run.py

To filter the testing add a language (or list of them) and a problem number (or list of them)

    python testing/run.py cpp
    python testing/run.py python
    python testing/run.py cpp python
    python testing/run.py cpp 1
    python testing/run.py cpp 1 2 99 142
    python testing/run.py cpp haskell 1
    python testing/run.py cpp haskell 42 69


## Solutions

Nothing here is groundbreaking, super minimal or extremely optimal code.
The solutions are of the most part coded upto getting the correct answer, then plopped into source control.
It's the actual completion of the problems that I'm aiming for!


## To do

* Make a seperate list of C solution, move C++ to using as much C++11 features as possible.
* Redo testing to allow for multiple solutions in the same language. (functional and imperative solutions, differnt approaches etc.)
* Have different run methods for languages that have the option to be interpreted and compiled.
* Make and store output data from the testing functionalilty
    * Include stats on the best and worst solutions from each language
    * Include some kind of graphic
    * Make a website with the github pages feature
