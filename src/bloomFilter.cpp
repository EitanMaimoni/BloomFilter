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
//geters
    std::vector<bool>& BloomFilter::get_bit_array() {
        return this->bit_array;
    }
    std::vector<std::string>& BloomFilter::get_black_list(){
        return this->black_list;
    }
    hFunc& BloomFilter::get_hFunc1(){
        return this->hFunc1;
    }
//seters
    void BloomFilter::set_bit_array(std::vector<bool>& bit_array){
        this->bit_array = bit_array;
    }
    void BloomFilter::set_black_list(std::vector<std::string>& black_list){
        this->black_list = black_list;
    }
