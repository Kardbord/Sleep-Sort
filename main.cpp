#include <iostream>
#include <cstdlib>
#include <string>
#include <thread>
#include <chrono>
#include <functional>

#include "SyncedVec.hpp"

// change to a larger uint to sort larger numbers
using _uint_ = uint32_t;

bool validateInputs(int const & argc) {
    // 1st cmd arg is the program name
    if (argc < 2) {
        std::cout << "No cmd arguments provided.\n"
                  << "Please provide a list of numbers to sort." << std::endl;
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

void threadStart(SyncedVec<_uint_> & sortedList, _uint_ const & num) {
    std::this_thread::sleep_for(std::chrono::milliseconds(num));
    sortedList.push_back(num);
}

void sleep_sort(SyncedVec<_uint_> & c, SyncedVec<_uint_> & sortedList) {
    std::vector<std::thread> threads;
    for (int i = 0; i < c.size(); ++i) {
        threads.push_back(std::thread(threadStart, std::ref(sortedList), *c[i]));
    }

    for (auto && th : threads) th.join();
}

// Input Arguments:
//  - Path to an input file
//  XOR
//  - Positive numbers to be sorted
int main(int argc, char **argv) {
    if (!validateInputs(argc)) return EXIT_FAILURE;

    SyncedVec<_uint_> c;

    SyncedVec<_uint_> sortedList;

    initVec(argc, argv, c);
    sleep_sort(c, sortedList);

    for (int i = 0; i < sortedList.size(); ++i) {
        std::cout << *sortedList[i] << std::endl;
    }
    return EXIT_SUCCESS;
}
