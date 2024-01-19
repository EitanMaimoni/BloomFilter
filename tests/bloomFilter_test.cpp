#include <gtest/gtest.h>
#include "../src/bloomFilter.h" // here we include the code to be tested
#include "../src/hFunc.h" // here we include the code to be tested
int length=64;
//checking if we can add a url to the black list
    TEST(SanityCheck, ADD_URL) {
    BloomFilter bloom_filter(length, 1);
    std::string url = "www.blacklist.com";
    std::string url1 = "www.blacklist1.com";

    // Redirect std::cout to a stringstream for the first call
    std::stringstream ss1;
    std::streambuf* oldCout1 = std::cout.rdbuf(ss1.rdbuf());

    // Add URL to the BloomFilter
    bloom_filter.add_url_to_bloomFilter(url);

    // Capture the content of the stringstream for the first call
    std::string output1 = ss1.str();

    // Restore the original std::cout
    std::cout.rdbuf(oldCout1);

    // Check the content of the stringstream for the first call
    EXPECT_EQ(output1, "");

    // Redirect std::cout to a new stringstream for the second call
    std::stringstream ss2;
    std::streambuf* oldCout2 = std::cout.rdbuf(ss2.rdbuf());

    // Check the second URL
    bloom_filter.check_url(url1);

    // Capture the content of the stringstream for the second call
    std::string output2 = ss2.str();

    // Restore the original std::cout
    std::cout.rdbuf(oldCout2);

    // Check the content of the stringstream for the second call
    EXPECT_EQ(output2, "false\n");
}



