#include <iostream>
#include "../include/solver.h"

int main() {

    std::string input;
    std::cin >> input;
    
    rnaSeq rnaseq(input);

    std::cout << solve(rnaseq) << std::endl;
}

/*
Build instructions:
$ make
$ ./bin/main
*/