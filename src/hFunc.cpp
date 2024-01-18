#include "hFunc.h"
#include <algorithm>
//constructor
 hFunc::hFunc(int number) {
    this->numOfHash = number;
}

void hFunc::activateFunction(std::string& url) {
    if (this->numOfHash == 1)
    {
        this->numOfHash = std::hash<std::string>{}(url);

    }else if (this->numOfHash == 2)
    {
        int firstHash = std::hash<std::string>{}(url);
        this->numOfHash = std::hash<int>{}(firstHash);
    }
}