#include <iostream>
#include <cstdlib>

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

// Input Arguments:
//  - Path to an input file
//  XOR
//  - Positive numbers to be sorted
int main(int argc, char **argv) {
    if (!validateInputs(argc)) return EXIT_FAILURE;

    if (argc > 1) {
        // TODO: sort numbers
    } else {
        // TODO: open input file, sort numbers
    }

    return EXIT_SUCCESS;
}
