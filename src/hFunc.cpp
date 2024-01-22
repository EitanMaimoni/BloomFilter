#include "hFunc.h"

// Default constructor
hFunc::hFunc() {

    this->numOfHash = 1;

}

// Constructor
 hFunc::hFunc(int number) {

    this->numOfHash = number;

}

// Return the index from the hash function
size_t hFunc::activateFunction(std::string& url) {

    size_t index;

    // Check if the number of hash functions is 1 or 2
    if (this->numOfHash == 1) {
        // Hash the url
        index = std::hash<std::string>{}(url);
        return index;

    } else if (this->numOfHash == 2) {  
        // Hash the url twice
        index = std::hash<std::string>{}(std::to_string(std::hash<std::string>{}(url)));
        return  index;
    }
    return -1;

}