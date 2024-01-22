#include "bloomFilter.h"
#include "hFunc.h"
#include <iostream>

// Default constructor
BloomFilter::BloomFilter() {

    this->bit_array.assign(0, false);
    this->hFunc1 = hFunc();
    this->hFunc2Flag = false;
    black_list = std::vector<std::string>();

}

// Constructor with hash 1 function
BloomFilter::BloomFilter(int ArrayLength ,int firstHash) {

    this->bit_array.assign(ArrayLength, false);
    this->hFunc1 = hFunc(firstHash);
    this->hFunc2Flag = false;
    black_list = std::vector<std::string>();

}

// Constructor with hash 2 functions
BloomFilter::BloomFilter(int ArrayLength , int firstHash, int secondHash) {

    this->bit_array.assign(ArrayLength, false);
    this->hFunc1 = hFunc(firstHash);
    this->hFunc2 = hFunc(secondHash); 
    this->hFunc2Flag = true;
    black_list = std::vector<std::string>();
    
}  

// Getters
std::vector<bool>& BloomFilter::get_bit_array() {

    return this->bit_array;

}
std::vector<std::string>& BloomFilter::get_black_list(){

    return this->black_list;

}
hFunc& BloomFilter::get_hFunc1(){

   return this->hFunc1;

}
hFunc& BloomFilter::get_hFunc2(){

   return this->hFunc2;

}
bool BloomFilter::get_hFunc2Flag(){

   return this->hFunc2Flag;
   
}
