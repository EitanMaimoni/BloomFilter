// bloomFilter.cpp

#include "bloomFilter.h"
#include "hFunc.h"
#include <iostream>

BloomFilter::BloomFilter(int ArrayLength ,int firstHash) {
    this->hFunc1 = hFunc(firstHash);
    this->is_valid_hFunc = false;
    this->bit_array.assign(ArrayLength, false);
    black_list = std::vector<std::string>();
}

// Constructor with hash functions
BloomFilter::BloomFilter(int ArrayLength , int firstHash,int secondHash) {
    this->hFunc1 = hFunc(firstHash);
    this->hFunc2 = hFunc(secondHash); 
    this->bit_array.assign(ArrayLength, false);
    this->bit_array.assign(ArrayLength, false);
    black_list = std::vector<std::string>();
}
void BloomFilter::check(std::string& url){
    if(this->is_on_black_list(url)){
        printf("true ");
    }
    else{
        printf("false\n");
        return;
    }
    if(this->is_on_bit_array(url)){
        printf("true\n");   
    }
    else{
        printf("false\n");
    }
}   
bool BloomFilter::is_on_bit_array(std::string& url){
    //write me a print command
    std::string answer = url;
    // answer = std::to_string(std::hash<std::string>{}(answer) % this->bit_array.size());
    int index = this->hFunc1.activateFunction(answer);
    //if the url is in the bit arrasy
    if(this->bit_array[index % this->bit_array.size()]){
        //double check if the url is in the black list
        if(this->is_valid_hFunc){  
            index = this->hFunc2.activateFunction(answer);
            if(this->bit_array[index % this->bit_array.size()]){
                return true;
            }
            return false;
        }
        return true;
    }

    return false;
}
// Add URL to the black list
void BloomFilter::add_to_black_list(std::string& url) {
    this->black_list.push_back(url);
}

//check if the URL is in the black list
bool BloomFilter::is_on_black_list(std::string& url) {
    return std::find(this->black_list.begin(), this->black_list.end(), url) != this->black_list.end();
}

// Add URL to the bloom filter
void BloomFilter::add_url_to_bloomFilter(std::string& url) {
    // Add the URL to the black list
    add_to_black_list(url);
    // Add the URL to the bloom filter
    std::string answer = url;
    // answer = std::to_string(std::hash<std::string>{}(answer) % this->bit_array.size());
    int index = this->hFunc1.activateFunction(answer);
    this->bit_array[index % this->bit_array.size()]=true;

    if(this->is_valid_hFunc){
        index = this->hFunc2.activateFunction(answer);
        this->bit_array[index % this->bit_array.size()]=true;
    } 
}



