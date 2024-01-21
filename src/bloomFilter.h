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

  
    //geters and setters
    std::string& get_url();
    std::vector<bool>& get_bit_array();
    std::vector<std::string>& get_black_list();
    hFunc& get_hFunc1();
    hFunc& get_hFunc2();
    bool get_hFunc2Flag();

private:
    std::vector<bool> bit_array;  // Bit array for the bloom filter
    std::vector<std::string> black_list;  // Blacklisted URLs
    hFunc hFunc1;
    hFunc hFunc2;
    bool hFunc2Flag;   
    
};

#endif  // BLOOMFILTER_H
