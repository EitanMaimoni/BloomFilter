// BloomFilter.h
#ifndef BLOOMFILTER_H
#define BLOOMFILTER_H
#include <string>

class BloomFilter {
public:
    BloomFilter();
    // other members...
    void addUrl(std::string& url);
    bool isBlacklisted(std::string& url);
};

#endif