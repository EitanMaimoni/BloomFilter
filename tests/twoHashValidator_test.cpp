#include <gtest/gtest.h>
#include "../src/iValidator.h"
#include "../src/twoHashValidator.h"
#include <vector>

TEST(SanityCheckTwoHash, VALID_INPUT1) {
    twoHashValidator check = twoHashValidator();
    std::string url = "8 1 2";
    std::vector<std::string> expected = {"8", "1", "2"};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheckTwoHash, VALID_INPUT2) {
    twoHashValidator check = twoHashValidator();
    std::string url = "64 1 2";
    std::vector<std::string> expected = {"64", "1", "2"};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheckTwoHash, VALID_INPUT3) {
    twoHashValidator check = twoHashValidator();
    std::string url = "x y z";
    std::vector<std::string> expected = {};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheckTwoHash, VALID_INPUT4) {
    twoHashValidator check = twoHashValidator();
    std::string url = "8 x 1";
    std::vector<std::string> expected = {};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheckTwoHash, VALID_INPUT5) {
    twoHashValidator check = twoHashValidator();
    std::string url = "z";
    std::vector<std::string> expected = {};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheckTwoHash, VALID_INPUT6) {
    twoHashValidator check = twoHashValidator();
    std::string url = "64";
    std::vector<std::string> expected = {};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheckTwoHash, VALID_INPUT7) {
    twoHashValidator check = twoHashValidator();
    std::string url = "x 1 2";
    std::vector<std::string> expected = {};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheckTwoHash, VALID_INPUT8) {
    twoHashValidator check = twoHashValidator();
    std::string url = "8 1 2 x c v v";
    std::vector<std::string> expected = {"8", "1", "2"};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheckTwoHash, VALID_INPUT9) {
    twoHashValidator check = twoHashValidator();
    std::string url = "64 1 1 1 1 1 1 2";
    std::vector<std::string> expected = {"64", "1", "2"};
    EXPECT_EQ(check.validationCheck(url), expected);
}

