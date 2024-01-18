#include "bloomFilter.h"


int main() {
    
  BloomFilter bloom_filter(64, 1);
    std::string url = "www.blacklist.com";
    std::string url1 = "www.blacklist1.com";
    bloom_filter.add_url_to_bloomFilter(url);
    // bloom_filter.is_on_bit_array(url);
    // bloom_filter.is_on_bit_array(url1);    
    return 0;
}