#ifndef HFUNC
#define HFUNC_H

#include <vector>
#include <string>
#include <regex>
#include <stdexcept>

class hFunc {
    int numOfHash;
public:
    // Default constructor
    hFunc(int number);

    // Add URL to the bloom filter
    void activateFunction(std::string& url);

};

#endif  // HFUNC;