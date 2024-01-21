#include <gtest/gtest.h>
#include "../src/oneHashBloomFilterValidator.h"
#include <vector>

TEST(SanityCheck, VALID_INPUT) {
    validInitInput check = validInitInput();
    std::string url = "8 1 2";
    std::vector<int> expected = {8, 1, 2};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheck, VALID_INPUT1) {
    validInitInput check = validInitInput();
    std::string url = "64 1 2";
    std::vector<int> expected = {64, 1, 2};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheck, VALID_INPUT2) {
    validInitInput check = validInitInput();
    std::string url = "x y z";
    std::vector<int> expected = {};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheck, VALID_INPUT3) {
    validInitInput check = validInitInput();
    std::string url = "8 x 1";
    std::vector<int> expected = {};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheck, VALID_INPUT4) {
    validInitInput check = validInitInput();
    std::string url = "z";
    std::vector<int> expected = {};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheck, VALID_INPUT5) {
    validInitInput check = validInitInput();
    std::string url = "64";
    std::vector<int> expected = {};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheck, VALID_INPUT7) {
    validInitInput check = validInitInput();
    std::string url = "x 1 2";
    std::vector<int> expected = {};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheck, VALID_INPUT8) {
    validInitInput check = validInitInput();
    std::string url = "8 1 2 x c v v";
    std::vector<int> expected = {8, 1, 2};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheck, VALID_INPUT11) {
    validInitInput check = validInitInput();
    std::string url = "64 1 1 1 1 1 1 2";
    std::vector<int> expected = {64, 1, 2};
    EXPECT_EQ(check.validationCheck(url), expected);
}
