#ifndef CHECKURL_H
#define CHECKURL_H
#include "bloomFilter.h"
#include "Icommand.h"

class checkUrl: public Icommand{
    public:
        //constructor
        checkUrl(BloomFilter* bloomFilter) ;

        // Add URL to the bloom filter
        void execute(std::string& url)override;
    private:
        //pointer to the bloom filter
        BloomFilter* bloomFilter;

        bool is_on_bit_array(std::string& url);
        bool is_on_black_list(std::string& url);
        void check_url(std::string& url);
};
#endif  // CHECKURL_H