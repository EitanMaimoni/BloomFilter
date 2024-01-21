#ifndef HFUNC_H
#define HFUNC_H

#include <vector>
#include <string>
#include <regex>
#include <stdexcept>

class hFunc {
    public:
    // Default constructor
    hFunc();
    //  constructor
    hFunc(int number);

    // Add URL to the bloom filter
    size_t activateFunction(std::string& url);

private:
    int numOfHash; 
};

#endif  // HFUNC;