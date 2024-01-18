#ifndef HFUNC
#define HFUNC_H

#include <vector>
#include <string>
#include <regex>
#include <stdexcept>

class hFunc {
    public:
    hFunc();

     //  constructor
    hFunc(int number);

     // Add URL to the bloom filter
    int activateFunction(std::string& url);

private:
    int numOfHash;
      
};

#endif  // HFUNC;