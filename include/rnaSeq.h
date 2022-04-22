#pragma once

#include <string>
#include <cassert>

char complement_base(char);

class rnaSeq {
    std::string seq;

public:
    rnaSeq(const std::string &);

    char &operator [] (size_t);

    bool valid();

    size_t length();
};