#include <iostream>
#include <cstdlib>

bool validateInputs(int const & argc) {
    if (argc < 1) {
        std::cout << "No cmd arguments provided.\n"
                  << "Please provide either a filepath or a list of numbers to sort." << std::endl;
        return false;
    }
    return true;
}



// Input Arguments:
//  [1] Path to an input file
//  [2] Numbers to be sorted
int main(int argc, char **argv) {
    if (!validateInputs(argc)) return EXIT_FAILURE;

    return EXIT_SUCCESS;
}
