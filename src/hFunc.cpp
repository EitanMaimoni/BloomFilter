#include "hFunc.h"

//default constructor
hFunc::hFunc() {

    this->numOfHash = 1;

}

//constructor
 hFunc::hFunc(int number) {

    this->numOfHash = number;

}

size_t hFunc::activateFunction(std::string& url) {
    size_t index;
    if (this->numOfHash == 1)
    {
        index = std::hash<std::string>{}(url);
        return index;
    }
    else if (this->numOfHash == 2)
    {
        index = std::hash<std::string>{}(url);
        index = std::hash<size_t>{}(index);
        return index;
    }
    return 0; // Return 0 or another suitable value if numOfHash is not 1 or 2
}