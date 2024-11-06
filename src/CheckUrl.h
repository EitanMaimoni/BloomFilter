#ifndef CHECKURL_H
#define CHECKURL_H
#include "BloomFilter.h"
#include "ICommand.h"
#include <string>

class CheckUrl: public ICommand{
    public:

        // Constructor
        CheckUrl(BloomFilter* bloomFilter) ;

        // Add URL to the bloom filter
        std::string execute(std::string& url)override;

    private:

        // Pointer to the bloom filter
        BloomFilter* bloomFilter;

        // Check if the URL is on the bit array
        bool isOnBitArray(std::string& url);

        // Check if the URL is on the black list
        bool isOnBlackList(std::string& url);

        // Check if the URL is blacklisted
        std::string checkUrl(std::string& url);

};
#endif  // CHECKURL_H