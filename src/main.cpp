#include <iostream>
#include "../include/solver.h"

int main() {

    std::string input;
    std::cin >> input;
    
    rnaSeq rnaseq(input);

    std::cout << solve(rnaseq) << std::endl;
}

/*
To build:
$ make
$ ./bin/main

To clean:
$ make clean
*/