//hFunc.cpp
#include "hFunc.h"


//constructor
 hFunc::hFunc(int number) {

    this->numOfHash = number;

}

int hFunc::activateFunction(std::string& url) {
    if (this->numOfHash == 1)
    {
       return std::hash<std::string>{}(url);

    }else if (this->numOfHash == 2)
    {
        int firstValue = std::hash<std::string>{}(url);
        return  std::hash<int>{}(firstValue);
    }
}