#include "../include/rnaSeq.h"

///Computes complement_base of given base
///
/// \param Input base
/// \return The complement base of the base taken as input
char complement_base(char c) {
    switch(c) {
        case 'A': return 'U';
        case 'C': return 'G';
        case 'G': return 'C';
        case 'U': return 'A';
        default: assert(false);
    }
}

///Initializes the rnaSeq
///
/// \param seq Input String
rnaSeq::rnaSeq(const std::string &seq) {
    this->seq = seq;
}

/// Convert 1-based to 0-based
///
/// \param idx Size of base
/// \return 0-based sequence
char &rnaSeq::operator [] (size_t idx) {
    return seq[idx - 1]; 
}

///checks if the sequence taken as input is valid
///
/// \return True if sequence is valid
bool rnaSeq::valid() {
    for(char c: seq)
        if(c != 'A' && c != 'C' && c != 'G' && c != 'U')
            return false;
    return true;
}

///Computes length of sequence
///
/// \return Length of sequence
size_t rnaSeq::length() {
    return seq.length();
}