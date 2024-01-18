#include <gtest/gtest.h>
#include "../src/bloomFilter.h" // here we include the code to be tested
#include "../src/hFunc.h" // here we include the code to be tested

//checking if we can add a url to the black list
TEST(SanityCheck, ADD_URL) {
    BloomFilter bloom_filter(100, 1);
    std::string url = "www.blacklist.com";
    bloom_filter.add_url_to_bloomFilter(url);
    EXPECT_TRUE(bloom_filter.is_on_bit_array(url));
}
TEST(SanityCheck, ADD_URL1) {
    BloomFilter bloom_filter(100, 1);
    std::string url = "www.blacklist.com";
    bloom_filter.add_url_to_bloomFilter(url);
    EXPECT_TRUE(bloom_filter.is_on_black_list(url));
}