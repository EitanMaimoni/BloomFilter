#include <gtest/gtest.h>
#include "../src/addUrl.h"
#include "../src/checkUrl.h"
#include "../src/bloomFilter.h" 
#include "../src/Icommand.h"
int length=64;
 TEST(SanityCheck, ADD_URL) {
    BloomFilter bloom_filter(1, 1,2);
    addUrl add_url(&bloom_filter);
    checkUrl check_url(&bloom_filter);
    std::string url = "www.blacklist.com";
    std::string url1 = "www.blacklist1.com";
    // Redirect std::cout to a stringstream for the first call
    std::stringstream ss1;
    std::streambuf* oldCout1 = std::cout.rdbuf(ss1.rdbuf());
    // Add URL to the BloomFilter
    add_url.execute(url);
    check_url.execute(url);
    // Capture the content of the stringstream for the first call
    std::string output1 = ss1.str();

    // Restore the original std::cout
    std::cout.rdbuf(oldCout1);
    // Check the content of the stringstream for the first call
    EXPECT_EQ(output1, "true true\n");

    // Redirect std::cout to a new stringstream for the second call
    std::stringstream ss2;
    std::streambuf* oldCout2 = std::cout.rdbuf(ss2.rdbuf());

    // Check the second URL
    check_url.execute(url1);

    // Capture the content of the stringstream for the second call
    std::string output2 = ss2.str();

    // Restore the original std::cout
    std::cout.rdbuf(oldCout2);

    // Check the content of the stringstream for the second call
    EXPECT_EQ(output2, "true false\n");
}
    TEST(SanityCheck, ADD_URL1) {
    BloomFilter bloom_filter(length, 1);
    std::string url = "www.blacklist.com";
    std::string url1 = "www.blacklist1.com";
    addUrl add_url(&bloom_filter);
    checkUrl check_url(&bloom_filter);
    // Redirect std::cout to a stringstream for the first call
    std::stringstream ss1;
    std::streambuf* oldCout1 = std::cout.rdbuf(ss1.rdbuf());
    // Add URL to the BloomFilter
    add_url.execute(url);
    check_url.execute(url);
    // Capture the content of the stringstream for the first call
    std::string output1 = ss1.str();

    // Restore the original std::cout
    std::cout.rdbuf(oldCout1);
    // Check the content of the stringstream for the first call
    EXPECT_EQ(output1, "true true\n");

    // Redirect std::cout to a new stringstream for the second call
    std::stringstream ss2;
    std::streambuf* oldCout2 = std::cout.rdbuf(ss2.rdbuf());

    // Check the second URL
    check_url.execute(url1);

    // Capture the content of the stringstream for the second call
    std::string output2 = ss2.str();

    // Restore the original std::cout
    std::cout.rdbuf(oldCout2);

    // Check the content of the stringstream for the second call
    EXPECT_EQ(output2, "false\n");
}
 TEST(ProfessorTests, first) {
    BloomFilter bloom_filter(8, 1,2);
    std::string url = "www.example.com0";
    std::string url1 = "www.example.com1";
    std::string url2 = "www.example.com11";
    addUrl add_url(&bloom_filter);
    checkUrl check_url(&bloom_filter);
    std::stringstream ss1;
    std::streambuf* oldCout1 = std::cout.rdbuf(ss1.rdbuf());
    check_url.execute(url);
    std::string output1 = ss1.str();
    std::cout.rdbuf(oldCout1);
    EXPECT_EQ(output1, "false\n");
    add_url.execute(url);
    std::stringstream ss2;
    std::streambuf* oldCout2 = std::cout.rdbuf(ss2.rdbuf());

   
    check_url.execute(url);


    std::string output2 = ss2.str();

    
    std::cout.rdbuf(oldCout2);
    EXPECT_EQ(output2, "true true\n");
    std::stringstream ss3;
    std::streambuf* oldCout3 = std::cout.rdbuf(ss3.rdbuf());

    
    check_url.execute(url1);

    std::string output3 = ss3.str();
    std::cout.rdbuf(oldCout3);

    EXPECT_EQ(output3, "false\n");
    std::stringstream ss4;
    std::streambuf* oldCout4 = std::cout.rdbuf(ss4.rdbuf());

    check_url.execute(url2);
    std::string output4 = ss4.str();
    std::cout.rdbuf(oldCout4);
    EXPECT_EQ(output4, "true false\n");
}
 
 TEST(ProfessorTests, second) {
    BloomFilter bloom_filter(8, 1);
    std::string url = "www.example.com0";
    std::string url1 = "www.example.com1";
    addUrl add_url(&bloom_filter);
    checkUrl check_url(&bloom_filter);
    add_url.execute(url);    
    std::stringstream ss1;
    std::streambuf* oldCout1 = std::cout.rdbuf(ss1.rdbuf());
    check_url.execute(url);
    std::string output1 = ss1.str();
    std::cout.rdbuf(oldCout1);
    EXPECT_EQ(output1, "true true\n");
    std::stringstream ss2;
    std::streambuf* oldCout2 = std::cout.rdbuf(ss2.rdbuf());
    check_url.execute(url1);
    std::string output2 = ss2.str();
    std::cout.rdbuf(oldCout2);
    EXPECT_EQ(output2, "true false\n");
}
TEST(ProfessorTests, third) {
    BloomFilter bloom_filter(8, 2);
    std::string url = "www.example.com0";
    std::string url1 = "www.example.com4";
    addUrl add_url(&bloom_filter);
    checkUrl check_url(&bloom_filter);
    add_url.execute(url);    
    std::stringstream ss1;
    std::streambuf* oldCout1 = std::cout.rdbuf(ss1.rdbuf());
    check_url.execute(url);
    std::string output1 = ss1.str();
    std::cout.rdbuf(oldCout1);
    EXPECT_EQ(output1, "true true\n");
    std::stringstream ss2;
    std::streambuf* oldCout2 = std::cout.rdbuf(ss2.rdbuf());
    check_url.execute(url1);
    std::string output2 = ss2.str();
    std::cout.rdbuf(oldCout2);
    EXPECT_EQ(output2, "true false\n");
}
