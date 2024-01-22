#ifndef HFUNC_H
#define HFUNC_H

#include <vector>
#include <string>
#include <regex>
#include <stdexcept>

class HFunc {
    public:

    // Default constructor
    HFunc();

    //  Constructor
    HFunc(int number);

    // Add URL to the bloom filter
    size_t activateFunction(std::string& url);

private:

    // Number of repetitions
    int numOfHash; 

};

#endif  // HFUNC;