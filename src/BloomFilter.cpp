#include "BloomFilter.h"
#include "HFunc.h"
#include <iostream>

// Default constructor
BloomFilter::BloomFilter() {

    this->bitArray.assign(0, false);
    this->hFunc1 = HFunc();
    this->hFunc2Flag = false;
    blackList = std::vector<std::string>();

}

// Constructor with hash 1 function
BloomFilter::BloomFilter(int ArrayLength ,int firstHash) {

    this->bitArray.assign(ArrayLength, false);
    this->hFunc1 = HFunc(firstHash);
    this->hFunc2Flag = false;
    blackList = std::vector<std::string>();

}

// Constructor with hash 2 functions
BloomFilter::BloomFilter(int ArrayLength , int firstHash, int secondHash) {

    this->bitArray.assign(ArrayLength, false);
    this->hFunc1 = HFunc(firstHash);
    this->hFunc2 = HFunc(secondHash); 
    this->hFunc2Flag = true;
    blackList = std::vector<std::string>();
    
}  

// Getters
std::vector<bool>& BloomFilter::getBitArray() {

    return this->bitArray;

}
std::vector<std::string>& BloomFilter::getBlackList(){

    return this->blackList;

}
HFunc& BloomFilter::getHFunc1(){

   return this->hFunc1;

}
HFunc& BloomFilter::getHFunc2(){

   return this->hFunc2;

}
bool BloomFilter::getHFunc2Flag(){

   return this->hFunc2Flag;
   
}