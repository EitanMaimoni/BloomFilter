#ifndef CHECKURL_H
#define CHECKURL_H
#include "bloomFilter.h"
#include "Icommand.h"

class checkUrl: public Icommand{
    public:

        // Constructor
        checkUrl(BloomFilter* bloomFilter) ;

        // Add URL to the bloom filter
        void execute(std::string& url)override;

    private:

        // Pointer to the bloom filter
        BloomFilter* bloomFilter;

        // Check if the URL is on the bit array
        bool is_on_bit_array(std::string& url);

        // Check if the URL is on the black list
        bool is_on_black_list(std::string& url);

        // Check if the URL is blacklisted
        void check_url(std::string& url);

};
#endif  // CHECKURL_H