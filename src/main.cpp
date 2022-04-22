#include <iostream>
#include "../include/solver.h"

int main() {
    // std::cout << "solve: " << solve() << std::endl;

    std::string input = "GGCGAAGAACCGGGGAGCC";
    rnaSeq rnaseq(input);
    std::cout << solve(rnaseq) << std::endl;
}