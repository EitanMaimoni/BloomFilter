#ifndef HFUNC
#define HFUNC_H

#include <vector>
#include <string>
#include <regex>
#include <stdexcept>

class hFunc {
    public:
     //  constructor
    hFunc(int number);

private:
  int numOfHash;

    // Add URL to the bloom filter
    void activateFunction(std::string& url);

};

#endif  // HFUNC;