#include <gtest/gtest.h>
#include "../src/twoHashBloomFilterValidator.h"
#include <vector>

TEST(SanityCheck, VALID_INPUT) {
    validInitInputTwo check = validInitInputTwo();
    std::string url = "8 1";
    std::vector<int> expected = {8, 1};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheck, VALID_INPUT1) {
    validInitInputTwo check = validInitInputTwo();
    std::string url = "64 1";
    std::vector<int> expected = {64, 1};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheck, VALID_INPUT2) {
    validInitInputTwo check = validInitInputTwo();
    std::string url = "x y z";
    std::vector<int> expected = {};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheck, VALID_INPUT3) {
    validInitInputTwo check = validInitInputTwo();
    std::string url = "8 x 1";
    std::vector<int> expected = {};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheck, VALID_INPUT4) {
    validInitInputTwo check = validInitInputTwo();
    std::string url = "z";
    std::vector<int> expected = {};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheck, VALID_INPUT5) {
    validInitInputTwo check = validInitInputTwo();
    std::string url = "64";
    std::vector<int> expected = {};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheck, VALID_INPUT7) {
    validInitInputTwo check = validInitInputTwo();
    std::string url = "x 1 2";
    std::vector<int> expected = {};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheck, VALID_INPUT8) {
    validInitInputTwo check = validInitInputTwo();
    std::string url = "8 1 2 x c v v";
    std::vector<int> expected = {8, 1};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheck, VALID_INPUT11) {
    validInitInputTwo check = validInitInputTwo();
    std::string url = "64 1 1 1 1 1 1";
    std::vector<int> expected = {64, 1};
    EXPECT_EQ(check.validationCheck(url), expected);
}
