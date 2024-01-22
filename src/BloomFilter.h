#ifndef BLOOMFILTER_H
#define BLOOMFILTER_H

#include <vector>
#include <string>
#include <regex>
#include <stdexcept>
#include "HFunc.h"

class BloomFilter {
public:

    // Default constructor
    BloomFilter();

    // Constructor with hash function
    BloomFilter(int ArrayLength ,int firstHash);

    // Constructor with hash functions
    BloomFilter(int ArrayLength , int firstHash, int secondHash);

    // Getters
    std::string& getUrl();
    std::vector<bool>& getBitArray();
    std::vector<std::string>& getBlackList();
    HFunc& getHFunc1();
    HFunc& getHFunc2();
    bool getHFunc2Flag();

private:

    // Bit array for the bloom filter
    std::vector<bool> bitArray;  

    // Blacklisted URLs
    std::vector<std::string> blackList; 

    // First hash function 
    HFunc hFunc1;

    // Second hash function
    HFunc hFunc2;

    // Flag for the second hash function
    bool hFunc2Flag;  
     
};

#endif  // BLOOMFILTER_H
