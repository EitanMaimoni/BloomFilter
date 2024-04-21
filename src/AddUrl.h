#ifndef ADDURL_H
#define ADDURL_H

#include "BloomFilter.h"
#include "ICommand.h"

class AddUrl: public ICommand{
    public:

        // Constructor
        AddUrl(BloomFilter* bloomFilter);

        // Add URL to the bloom filter
         std::string execute(std::string& url)override;

    private:

        // Pointer to the bloom filter
        BloomFilter* bloomFilter;

        // Add URL to the black list
        void addToBlackList(std::string& url);

        // Add URL to the bit array
        void addToBitArray(std::string& url);

};
#endif  // ADDURL_H