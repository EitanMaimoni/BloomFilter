#include <gtest/gtest.h>
#include "../src/bloomFilterValidator.h"
#include "../src/twoHashBloomFilterValidator.h"
#include <vector>

TEST(SanityCheckTwoHash, VALID_INPUT1) {
    twoHashBloomFilterValidator check = twoHashBloomFilterValidator();
    std::string url = "8 1 2";
    std::vector<int> expected = {8, 1, 2};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheckTwoHash, VALID_INPUT2) {
    twoHashBloomFilterValidator check = twoHashBloomFilterValidator();
    std::string url = "64 1 2";
    std::vector<int> expected = {64, 1, 2};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheckTwoHash, VALID_INPUT3) {
    twoHashBloomFilterValidator check = twoHashBloomFilterValidator();
    std::string url = "x y z";
    std::vector<int> expected = {};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheckTwoHash, VALID_INPUT4) {
    twoHashBloomFilterValidator check = twoHashBloomFilterValidator();
    std::string url = "8 x 1";
    std::vector<int> expected = {};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheckTwoHash, VALID_INPUT5) {
    twoHashBloomFilterValidator check = twoHashBloomFilterValidator();
    std::string url = "z";
    std::vector<int> expected = {};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheckTwoHash, VALID_INPUT6) {
    twoHashBloomFilterValidator check = twoHashBloomFilterValidator();
    std::string url = "64";
    std::vector<int> expected = {};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheckTwoHash, VALID_INPUT7) {
    twoHashBloomFilterValidator check = twoHashBloomFilterValidator();
    std::string url = "x 1 2";
    std::vector<int> expected = {};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheckTwoHash, VALID_INPUT8) {
    twoHashBloomFilterValidator check = twoHashBloomFilterValidator();
    std::string url = "8 1 2 x c v v";
    std::vector<int> expected = {8, 1, 2};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheckTwoHash, VALID_INPUT9) {
    twoHashBloomFilterValidator check = twoHashBloomFilterValidator();
    std::string url = "64 1 1 1 1 1 1 2";
    std::vector<int> expected = {64, 1, 2};
    EXPECT_EQ(check.validationCheck(url), expected);
}

