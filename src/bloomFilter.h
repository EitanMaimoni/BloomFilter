#ifndef BLOOMFILTER_H
#define BLOOMFILTER_H

#include "hFunc.h"
#include <vector>
#include <string>
#include <regex>
#include <stdexcept>
#include <map>

class BloomFilter {
public:
    // Default constructor
    BloomFilter();
    // Constructor with hash function
    BloomFilter(int ArrayLength ,int firstHash);
    // Constructor with hash functions
    BloomFilter(int ArrayLength , int firstHash, int secondHash);

    // Add URL to the bloom filter
    void add_url_to_bloomFilter(std::string& url);
    // Check if the URL is blacklisted
    void check_url(std::string& url);
    //geters and setters
    std::string& get_url();
    std::vector<bool>& get_bit_array();
    std::vector<std::string>& get_black_list();
    hFunc& get_hFunc1();
    hFunc& get_hFunc2();
    bool get_hFunc2Flag();
    void set_bit_array(std::vector<bool>& bit_array);
    void set_black_list(std::vector<std::string>& black_list);

private:
    std::vector<bool> bit_array;  // Bit array for the bloom filter
    std::vector<std::string> black_list;  // Blacklisted URLs
    hFunc hFunc1;
    hFunc hFunc2;
    bool hFunc2Flag;
    std::map<int, Icommand*> map;
    
    // Add URL to the black list
    void add_to_black_list(std::string& url);
    // Add URL to the 
    void add_to_bit_array(std::string& url);
    // Check if the URL is in the bit array
    bool is_on_bit_array(std::string& url);
    // Check if the URL is in the black list
    bool is_on_black_list(std::string& url);  
};

#endif  // BLOOMFILTER_H
