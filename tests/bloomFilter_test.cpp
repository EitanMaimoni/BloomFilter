#include <gtest/gtest.h>
#include "../src/bloomFilter.cpp" // here we include the code to be tested

//this test is to check if the bloom filter is working properly
TEST(SanityCheck, ADD_URL) {
    BloomFilter bloom_filter;
    std::string url = "blacklist.com";
    bloom_filter.addUrl(url);
    EXPECT_TRUE(bloom_filter.check_url(url));
}

TEST(SanityCheck, NOT_BLACKLISTED_URL) {
    BloomFilter bloom_filter;
    std::string url = "www.notblacklisted.com";
    EXPECT_FALSE(bloom_filter.check_url(url));
}

TEST(UNVALID_URL, ADD_BASIC_URL1) {
    BloomFilter bloom_filter;  
    std::string url = "imNotURL.com";
    ASSERT_THROW(bloom_filter.add_to_black_list(url), std::invalid_argument);
}

TEST(UNVALID_URL, ADD_BASIC_URL2) {
    BloomFilter bloom_filter;
    std::string url = ".imNotURL.com";
    ASSERT_THROW(bloom_filter.add_to_black_list(url), std::invalid_argument);
}

TEST(UNVALID_URL, ADD_BASIC_URL3) {
    BloomFilter bloom_filter;
    std::string url = "www..com";
    ASSERT_THROW(bloom_filter.add_to_black_list(url), std::invalid_argument);
}

TEST(UNVALID_URL, ADD_BASIC_URL4) {
    BloomFilter bloom_filter;
    std::string url = "www.com";
    ASSERT_THROW(bloom_filter.add_to_black_list(url), std::invalid_argument);
}

TEST(UNVALID_URL, ADD_BASIC_URL5) {
    BloomFilter bloom_filter;
    std::string url = "www.imNotURL.";
    ASSERT_THROW(bloom_filter.add_to_black_list(url), std::invalid_argument);
}

TEST(UNVALID_URL, ADD_BASIC_URL6) {
    BloomFilter bloom_filter;
    std::string url = "www.imNotURL";
    ASSERT_THROW(bloom_filter.add_to_black_list(url), std::invalid_argument);
}

TEST(UNVALID_URL, CHECK_BASIC_URL1) {
    BloomFilter bloom_filter;
    std::string url = "imNotURL.com";
    ASSERT_THROW(bloom_filter.check_url(url), std::invalid_argument);
}

TEST(UNVALID_URL, DOUBLE_CHECK_BASIC_URL1) {
    BloomFilter bloom_filter;
    std::string url = "www.imNotURL";
    ASSERT_THROW(bloom_filter.double_check_url(url), std::invalid_argument);
}