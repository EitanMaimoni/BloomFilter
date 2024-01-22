#ifndef BLOOMFILTER_H
#define BLOOMFILTER_H

#include "hFunc.h"
#include <vector>
#include <string>
#include <regex>
#include <stdexcept>


class BloomFilter {
public:

    // Default constructor
    BloomFilter();

    // Constructor with hash function
    BloomFilter(int ArrayLength ,int firstHash);

    // Constructor with hash functions
    BloomFilter(int ArrayLength , int firstHash, int secondHash);

    // Getters
    std::string& get_url();
    std::vector<bool>& get_bit_array();
    std::vector<std::string>& get_black_list();
    hFunc& get_hFunc1();
    hFunc& get_hFunc2();
    bool get_hFunc2Flag();

private:

    // Bit array for the bloom filter
    std::vector<bool> bit_array;  

    // Blacklisted URLs
    std::vector<std::string> black_list; 

    // First hash function 
    hFunc hFunc1;

    // Second hash function
    hFunc hFunc2;

    // Flag for the second hash function
    bool hFunc2Flag;  
     
};

#endif  // BLOOMFILTER_H
