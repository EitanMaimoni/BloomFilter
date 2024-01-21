#ifndef ADDURL_H
#define ADDURL_H
#include "bloomFilter.h"
#include "Icommand.h"

class addUrl: public Icommand{
    public:
        //constructor
        addUrl(BloomFilter* bloomFilter);

        // Add URL to the bloom filter
        void execute(std::string& url)override;
    private:
        //pointer to the bloom filter
        BloomFilter* bloomFilter;

        // Add URL to the black list
        void add_to_black_list(std::string& url);

        // Add URL to the bit array
        void add_to_bit_array(std::string& url);
       
};
#endif  // ADDURL_H
