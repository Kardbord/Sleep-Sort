#include <iostream>
#include <cstdlib>
#include <string>

#include "SyncedVec.hpp"

// change to a larger uint to sort larger numbers
using _uint_ = uint32_t;

bool validateInputs(int const & argc) {
    if (argc < 1) {
        std::cout << "No cmd arguments provided.\n"
                  << "Please provide either a filepath or a list of numbers to sort." << std::endl;
        return false;
    }
    return true;
}

void initVec(int const & argc, char **argv, SyncedVec<_uint_> & c) {
    for (int i = 1; i < argc; ++i) {
        try {
            _uint_ u = std::stoul(std::string(argv[i]));
            c.push_back(u);
        } catch(std::exception e) {
            // Do nothing, keep trucking
        }
    }
}   

// Input Arguments:
//  - Path to an input file
//  XOR
//  - Positive numbers to be sorted
int main(int argc, char **argv) {
    if (!validateInputs(argc)) return EXIT_FAILURE;

    SyncedVec<_uint_> c;

    // 1st cmd arg is program name
    if (argc > 2) {
        initVec(argc, argv, c);
        for (int i = 0; i < c.size(); ++i) {
            if (c[i] != nullptr) std::cout << *c[i] << std::endl;
        }
        // TODO: sort numbers
    } else {
        // TODO: open input file, sort numbers
    }

    return EXIT_SUCCESS;
}
