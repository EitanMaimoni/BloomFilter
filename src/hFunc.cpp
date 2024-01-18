//hFunc.cpp
#include "hFunc.h"
#include <iostream>
hFunc::hFunc() {
    this->numOfHash = 0;
}

//constructor
 hFunc::hFunc(int number) {

    this->numOfHash = number;

}
size_t hFunc::activateFunction(std::string& url) {
    if (this->numOfHash == 1)
    {
        printf("hahaha");
        std::cout << std::hash<std::string>{}(url)<< std::endl;
        printf("hahaha");
        return std::hash<std::string>{}(url);

    }else if (this->numOfHash == 2)
    {
        std::string firstValue = std::to_string(std::hash<std::string>{}(url));
        return  std::hash<std::string>{}(firstValue);
    }
    return -1;
}