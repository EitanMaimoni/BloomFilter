#include <gtest/gtest.h>
#include "../src/bloomFilter.cpp" // here we include the code to be tested

//checking if we can add a url to the black list
TEST(SanityCheck, ADD_URL) {
    BloomFilter bloom_filter;
    std::string url = "www.blacklist.com";
    bloom_filter.add_url_to_bloomFilter(url);
    EXPECT_TRUE(bloom_filter.check_url(url));
}

//checking if unblacklisted url is not blacklisted
TEST(SanityCheck, NOT_BLACKLISTED_URL) {
    BloomFilter bloom_filter;
    std::string url = "www.notblacklisted.com";
    EXPECT_FALSE(bloom_filter.check_url(url));
}

//checking if we cant add unvalid url to the black list
TEST(UNVALID_URL, ADD_BASIC_URL1) {
    BloomFilter bloom_filter;  
    std::string url = "imNotURL.com";
    ASSERT_THROW(bloom_filter.add_url_to_bloomFilter(url), std::invalid_argument);
}

//checking if we cant add unvalid url to the black list
TEST(UNVALID_URL, ADD_BASIC_URL2) {
    BloomFilter bloom_filter;
    std::string url = ".imNotURL.com";
    ASSERT_THROW(bloom_filter.add_url_to_bloomFilter(url), std::invalid_argument);
}

//checking if we cant add unvalid url to the black list
TEST(UNVALID_URL, ADD_BASIC_URL3) {
    BloomFilter bloom_filter;
    std::string url = "www..com";
    ASSERT_THROW(bloom_filter.add_url_to_bloomFilter(url), std::invalid_argument);
}

//checking if we cant add unvalid url to the black list
TEST(UNVALID_URL, ADD_BASIC_URL4) {
    BloomFilter bloom_filter;
    std::string url = "www.com";
    ASSERT_THROW(bloom_filter.add_url_to_bloomFilter(url), std::invalid_argument);
}

//checking if we cant add unvalid url to the black list
TEST(UNVALID_URL, ADD_BASIC_URL5) {
    BloomFilter bloom_filter;
    std::string url = "www.imNotURL.";
    ASSERT_THROW(bloom_filter.add_url_to_bloomFilter(url), std::invalid_argument);
}

//checking if we cant add unvalid url to the black list
TEST(UNVALID_URL, ADD_BASIC_URL6) {
    BloomFilter bloom_filter;
    std::string url = "www.imNotURL";
    ASSERT_THROW(bloom_filter.add_url_to_bloomFilter(url), std::invalid_argument);
}

//checking if we cant add unvalid url to the black list
TEST(UNVALID_URL, CHECK_BASIC_URL1) {
    BloomFilter bloom_filter;
    std::string url = "imNotURL.com";
    ASSERT_THROW(bloom_filter.check_url(url), std::invalid_argument);
}

//checking if we cant add unvalid url to the black list
TEST(UNVALID_URL, DOUBLE_CHECK_BASIC_URL1) {
    BloomFilter bloom_filter;
    std::string url = "www.imNotURL";
    ASSERT_THROW(bloom_filter.check_url(url), std::invalid_argument);
}