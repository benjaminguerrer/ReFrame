# ReFrame
A simple reframing calculator made in C++11 for the Terminal. It's designed to find either relative focal length or distance, to maintain same framing on subject. Coded in VSCode 1.82.2, Linux OS Xubuntu 22.04.3 LTS.
## Inputs
The code takes as input, in order, these four values: current focal length, current distance from subject, target static value, and type of operation (either find focal length or distance, with a char input 'd' or 'f', either upper or lower cased)
## Running the program
Just open the run.sh file, and it will execute the program in a Terminal.
## Compiling the program
If you feel uncomfortable executing the compiled version, just run the following in a command line, in project directory:
```shell
$ g++ -o <ReFrame> ReFrame.cpp
```
That way you will have your own personal compile.
