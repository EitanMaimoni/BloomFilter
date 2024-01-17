// BloomFilter.h
#ifndef BLOOMFILTER_H
#define BLOOMFILTER_H
#include <string>
#include <vector>

class BloomFilter {
    std::vector<bool> bit_array;
    std::vector<std::string> black_list;
    std::vector<int> hash_functions;
public:
    BloomFilter();
    BloomFilter(std::vector<int> args);
    // other members...
    void addUrl(std::string& url);
    void add_to_black_list(std::string& url);
    bool check_url(std::string& url);
    bool double_check_url(std::string& url);
};

#endif