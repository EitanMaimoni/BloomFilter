#include "bloomFilter.h"
#include "hFunc.h"
#include <iostream>

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

// Check if the URL is in the bit array
bool BloomFilter::is_on_bit_array(std::string& url){
    size_t index = this->hFunc1.activateFunction(url);

    //check if the bit is true
    if(this->bit_array[index % this->bit_array.size()]){
        //check if the second hash function is on
        if(this->hFunc2Flag){  
            index = this->hFunc2.activateFunction(url);
            //check if the bit is true
            if(this->bit_array[index % this->bit_array.size()]){
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}

// Check if the URL is in the black list
bool BloomFilter::is_on_black_list(std::string& url) {
    return std::find(this->black_list.begin(), this->black_list.end(), url) != this->black_list.end();
}

// Add URL to the black list
void BloomFilter::add_to_black_list(std::string& url) {
    this->black_list.push_back(url);
}

// Add URL to the bit array
void BloomFilter::add_to_bit_array(std::string& url){
    size_t index = this->hFunc1.activateFunction(url);

    this->bit_array[index % this->bit_array.size()] = true;

    if(this->hFunc2Flag){
        index = this->hFunc2.activateFunction(url);
        this->bit_array[index % this->bit_array.size()] = true;
    } 
}


// Add URL to the bloom filter
void BloomFilter::add_url_to_bloomFilter(std::string& url) {
    // Add the URL to the black list
    add_to_black_list(url);
    // Add the URL to the bit array filter
    add_to_bit_array(url);  
}

// Check if the URL is blacklisted
void BloomFilter::check_url(std::string& url){
    if(this->is_on_bit_array(url)){
        printf("true ");
    }
    else{
        printf("false\n");
        return;
    }
    if(this->is_on_black_list(url)){
        printf("true\n");   
    }
    else{
        printf("false\n");
    }
}



