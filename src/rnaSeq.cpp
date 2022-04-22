#include "../include/rnaSeq.h"

char complement_base(char c) {
    switch(c) {
        case 'A': return 'U';
        case 'C': return 'G';
        case 'G': return 'C';
        case 'U': return 'A';
        default: assert(false);
    }
}

rnaSeq::rnaSeq(const std::string &seq) {
    this->seq = seq;
}

char &rnaSeq::operator [] (size_t idx) {
    return seq[idx - 1]; // convert 1-based to 0-based
}

bool rnaSeq::valid() {
    for(char c: seq)
        if(c != 'A' && c != 'C' && c != 'G' && c != 'U')
            return false;
    return true;
}

size_t rnaSeq::length() {
    return seq.length();
}