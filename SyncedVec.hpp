#ifndef _SYNCED_VEC_HPP
#define _SYNCED_VEC_HPP

#include <vector>
#include <mutex>

// A thread-safe version of a std::vector<T>
//
// Note that SyncedVec objects cannot be passed by const reference or copied due to 
// the private std::mutex member, m_mutex
//
// Note that this class does not necessarily provide all functionality a std::vector does
template <typename T>
class SyncedVec {
public:

    // ----------------------------- CONSTRUCTORS ---------------------------------------- //

    SyncedVec() : m_vec(), m_mutex() {}

    // No copy construction allowed
    SyncedVec(SyncedVec const&) = delete;

    // ------------------------ PUBLIC MEMBER FUNCTIONS ---------------------------------- //

    // No copy assignment allowed
    SyncedVec& operator=(SyncedVec const&) = delete;

private:

    // ------------------------ VARIABLES AND CONSTANTS ---------------------------------- //

    std::vector<T> m_vec;

    std::mutex m_mutex;

    // ------------------------ PRIVATE MEMBER FUNCTIONS ---------------------------------- //
};

#endif
