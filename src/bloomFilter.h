// bloomFilter.h

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
    BloomFilter(int ArrayLength ,int firstHash);

    // Constructor with hash functions
    BloomFilter(int ArrayLength , int firstHash,int secondHash);

    // Add URL to the bloom filter
    void add_url_to_bloomFilter(std::string& url);

    // Check if the URL is blacklisted
    bool check_url(std::string& url);
    bool is_on_bit_array(std::string& url);


private:
    std::vector<bool> bit_array;  // Bit array for the bloom filter
    std::vector<std::string> black_list;  // Blacklisted URLs
    hFunc hFunc1;
    hFunc hFunc2;
    bool is_valid_hFunc;
    // Double-check if the URL is blacklisted
    bool is_on_black_list(std::string& url);

    // Add URL to the black list
    void add_to_black_list(std::string& url);

    // Validate if the provided string is a valid URL
    static bool is_valid_url(const std::string& url);
};

#endif  // BLOOMFILTER_H
