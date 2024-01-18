#include <gtest/gtest.h>
#include "../src/bloomFilter.h" // here we include the code to be tested
#include "../src/hFunc.h" // here we include the code to be tested
int length=64;
//checking if we can add a url to the black list
TEST(SanityCheck, ADD_URL) {
    BloomFilter bloom_filter(length, 1);
    std::string url = "www.blacklist.com";
    std::string url1 = "www.blacklist1.com";
    bloom_filter.add_url_to_bloomFilter(url);
    EXPECT_TRUE(bloom_filter.is_on_bit_array(url));
    EXPECT_FALSE(bloom_filter.is_on_bit_array(url1));
}
TEST(SanityCheck, ADD_URL1) {
    BloomFilter bloom_filter(length, 1);
    std::string url = "www.blacklist.com";
    std::string url1 = "www.blacklist1.com";
    bloom_filter.add_url_to_bloomFilter(url);
    EXPECT_TRUE(bloom_filter.is_on_black_list(url));
    EXPECT_FALSE(bloom_filter.is_on_black_list(url1));
}
TEST(SanityCheck, ADD_URL2) {
    BloomFilter bloom_filter(length, 2);
    std::string url = "www.blacklist.com";
    std::string url1 = "www.blacklist1.com";
    bloom_filter.add_url_to_bloomFilter(url);
    EXPECT_TRUE(bloom_filter.is_on_bit_array(url));
    EXPECT_FALSE(bloom_filter.is_on_bit_array(url1));
}
TEST(SanityCheck, ADD_URL3) {
    BloomFilter bloom_filter(length, 2);
    std::string url = "www.blacklist.com";
    std::string url1 = "www.blacklist1.com";
    bloom_filter.add_url_to_bloomFilter(url);
    EXPECT_TRUE(bloom_filter.is_on_black_list(url));
    EXPECT_FALSE(bloom_filter.is_on_black_list(url1));
}
TEST(SanityCheck, ADD_URL4) {
    BloomFilter bloom_filter(length, 1,2);
    std::string url = "www.blacklist.com";
    std::string url1 = "www.blacklist1.com";
    bloom_filter.add_url_to_bloomFilter(url);
    EXPECT_TRUE(bloom_filter.is_on_bit_array(url));
    EXPECT_FALSE(bloom_filter.is_on_bit_array(url1));
}
TEST(SanityCheck, ADD_URL5) {
    BloomFilter bloom_filter(length, 1,2);
    std::string url = "www.blacklist.com";
    std::string url1 = "www.blacklist1.com";
    bloom_filter.add_url_to_bloomFilter(url);
    EXPECT_TRUE(bloom_filter.is_on_black_list(url));
    EXPECT_FALSE(bloom_filter.is_on_black_list(url1));
}
TEST(SanityCheck, ADD_URL6) {
    BloomFilter bloom_filter(length, 2,1);
    std::string url = "www.blacklist.com";
    std::string url1 = "www.blacklist1.com";
    bloom_filter.add_url_to_bloomFilter(url);
    EXPECT_TRUE(bloom_filter.is_on_bit_array(url));
    EXPECT_FALSE(bloom_filter.is_on_bit_array(url1));
}
TEST(SanityCheck, ADD_URL7) {
    BloomFilter bloom_filter(length, 2,1);
    std::string url = "www.blacklist.com";
    std::string url1 = "www.blacklist1.com";
    bloom_filter.add_url_to_bloomFilter(url);
    EXPECT_TRUE(bloom_filter.is_on_black_list(url));
    EXPECT_FALSE(bloom_filter.is_on_black_list(url1));
}
