#include <iostream>
#include "../include/solver.h"
///main function
///
/// \return Returns 0 on successful compilation
int main() {

    std::string input;
    std::cin >> input;
    
    rnaSeq rnaseq(input);

    auto ans = solve(rnaseq);
    std::cout << ans.size() << std::endl;
    for(auto [l, r]: ans)
        std::cout << l << ' ' << r << std::endl;

}

/*
To build:
$ make
$ ./bin/main

To clean:
$ make clean
*/