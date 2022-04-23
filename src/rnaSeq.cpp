#include "../include/rnaSeq.h"

///complement_base returns the complement base of the base taken as input
char complement_base(char c) {
    switch(c) {
        case 'A': return 'U';
        case 'C': return 'G';
        case 'G': return 'C';
        case 'U': return 'A';
        default: assert(false);
    }
}

///initializes the rnaSeq
rnaSeq::rnaSeq(const std::string &seq) {
    this->seq = seq;
}

/// convert 1-based to 0-based
char &rnaSeq::operator [] (size_t idx) {
    return seq[idx - 1]; 
}

///checks if the sequence taken as input is valid
bool rnaSeq::valid() {
    for(char c: seq)
        if(c != 'A' && c != 'C' && c != 'G' && c != 'U')
            return false;
    return true;
}

///returns length of sequence
size_t rnaSeq::length() {
    return seq.length();
}