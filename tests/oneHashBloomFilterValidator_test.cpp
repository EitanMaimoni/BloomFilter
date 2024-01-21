#include <gtest/gtest.h>
#include "../src/bloomFilterValidator.h"
#include "../src/oneHashBloomFilterValidator.h"
#include <vector>

TEST(SanityCheckOneHash, VALID_INPUT1) {
    oneHashBloomFilterValidator check = oneHashBloomFilterValidator();
    std::string url = "8 1";
    std::vector<int> expected = {8, 1};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheckOneHash, VALID_INPUT2) {
    oneHashBloomFilterValidator check = oneHashBloomFilterValidator();
    std::string url = "64 1";
    std::vector<int> expected = {64, 1};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheckOneHash, VALID_INPUT3) {
    oneHashBloomFilterValidator check = oneHashBloomFilterValidator();
    std::string url = "x y z";
    std::vector<int> expected = {};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheckOneHash, VALID_INPUT4) {
    oneHashBloomFilterValidator check = oneHashBloomFilterValidator();
    std::string url = "8 x 1";
    std::vector<int> expected = {};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheckOneHash, VALID_INPUT5) {
    oneHashBloomFilterValidator check = oneHashBloomFilterValidator();
    std::string url = "z";
    std::vector<int> expected = {};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheckOneHash, VALID_INPUT6) {
    oneHashBloomFilterValidator check = oneHashBloomFilterValidator();
    std::string url = "64";
    std::vector<int> expected = {};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheckOneHash, VALID_INPUT7) {
    oneHashBloomFilterValidator check = oneHashBloomFilterValidator();
    std::string url = "x 1 2";
    std::vector<int> expected = {};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheckOneHash, VALID_INPUT8) {
    oneHashBloomFilterValidator check = oneHashBloomFilterValidator();
    std::string url = "8 1 x c v v";
    std::vector<int> expected = {8, 1};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheckOneHash, VALID_INPUT9) {
    oneHashBloomFilterValidator check = oneHashBloomFilterValidator();
    std::string url = "64 1 1 1 1 1 1";
    std::vector<int> expected = {64, 1};
    EXPECT_EQ(check.validationCheck(url), expected);
}