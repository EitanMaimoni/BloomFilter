// bloomFilter.h

#ifndef BLOOMFILTER_H
#define BLOOMFILTER_H

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


private:
    std::vector<bool> bit_array;  // Bit array for the bloom filter
    std::vector<int> hash_functions;  // Hash functions for indexing
    std::vector<std::string> black_list;  // Blacklisted URLs

    // Double-check if the URL is blacklisted
    bool is_on_black_list(std::string& url);

    // Add URL to the black list
    void add_to_black_list(std::string& url);

    // Validate if the provided string is a valid URL
    static bool is_valid_url(const std::string& url);
};

#endif  // BLOOMFILTER_H
