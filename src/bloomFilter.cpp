#include "bloomFilter.h"

//default constructor
BloomFilter::BloomFilter() {
    this->bit_array.assign(1,false);
        black_list = std::vector<std::string>();
}

//constructor
BloomFilter::BloomFilter(std::vector<int> args) {
    //for each args we will add a hash function,
    //exept for the first one that will be the size of the bit array
    for (size_t i = 0; i < args.size(); i++)
    {
        if(i==0)
        {
            this->bit_array.assign(args[0],false);
            break;
        };
        this->hash_functions.push_back(args[i]);
    }
    black_list = std::vector<std::string>();
}

//add url to the bloom filter
void BloomFilter::addUrl(std::string& url){
    add_to_black_list(url);
    for (size_t i = 0; i < hash_functions.size(); i++)
    {
        std::string answer = url;
        for (int j = 0; j < hash_functions[i] ; j++)
        {
            answer = std::hash<std::string>{}(answer) % this->bit_array.size();
        }
        this->bit_array[std::stoi(answer)] = true;
    }
}

//add url to the black list
void BloomFilter::add_to_black_list(std::string& url) {
    this->black_list.push_back(url);
}

//check if the url is blacklisted
bool BloomFilter::check_url(std::string& url) {
    for (size_t i = 0; i < hash_functions.size(); i++)
    {
        std::string answer = url;
        for (int j = 0; j < hash_functions[i] ; j++)
        {
            answer = std::hash<std::string>{}(answer) % this->bit_array.size();
        }
        if (this->bit_array[std::stoi(answer)] = false)
        {
            return false;
        }
    } 
    return double_check_url(url);
}

//double check if the url is blacklisted
bool BloomFilter::double_check_url(std::string& url) {
    for (size_t i = 0; i < this->black_list.size(); i++)
    {
        if(this->black_list[i]==url){
            return true;
        }
    }
     return false; 
}
