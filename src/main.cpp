#include <iostream>
#include "../include/solver.h"

int main() {

    std::string input = "UUGCGUCGCGUCGACGAAGUCGC";
    std::cin >> input;
    rnaSeq rnaseq(input);

    std::cout << solve(rnaseq) << std::endl;
}