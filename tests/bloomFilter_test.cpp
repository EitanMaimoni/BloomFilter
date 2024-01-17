#include <gtest/gtest.h>
#include "../src/bloomFilter.cpp" // here we include the code to be tested
//this test is to check if the bloom filter is working properly
TEST(SumTest, TestAddUrl1) {
    BloomFilter bloomFilter;
    std::string url1 = "example.com";
    bloomFilter.addUrl(url1);
    EXPECT_TRUE(bloomFilter.isBlacklisted(url1));
}
TEST(SumTest2, TestAddUrl2) {
    BloomFilter bloomFilter;
    std::string url2 = "notblacklisted.com";
    bloomFilter.addUrl(url2);
    EXPECT_FALSE(bloomFilter.isBlacklisted(url2));
}