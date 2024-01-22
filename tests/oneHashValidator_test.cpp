#include <gtest/gtest.h>
#include "../src/OneHashValidator.h"
#include <vector>

TEST(SanityCheckOneHash, VALID_INPUT1) {
    OneHashValidator check = OneHashValidator();
    std::string url = "8 1";
    std::vector<std::string> expected = {"8", "1"};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheckOneHash, VALID_INPUT2) {
    OneHashValidator check = OneHashValidator();
    std::string url = "64 1";
    std::vector<std::string> expected = {"64", "1"};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheckOneHash, VALID_INPUT3) {
    OneHashValidator check = OneHashValidator();
    std::string url = "x y z";
    std::vector<std::string> expected = {};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheckOneHash, VALID_INPUT4) {
    OneHashValidator check = OneHashValidator();
    std::string url = "8 x 1";
    std::vector<std::string> expected = {};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheckOneHash, VALID_INPUT5) {
    OneHashValidator check = OneHashValidator();
    std::string url = "z";
    std::vector<std::string> expected = {};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheckOneHash, VALID_INPUT6) {
    OneHashValidator check = OneHashValidator();
    std::string url = "64";
    std::vector<std::string> expected = {};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheckOneHash, VALID_INPUT7) {
    OneHashValidator check = OneHashValidator();
    std::string url = "x 1 2";
    std::vector<std::string> expected = {};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheckOneHash, VALID_INPUT8) {
    OneHashValidator check = OneHashValidator();
    std::string url = "8 1 x c v v";
    std::vector<std::string> expected = {"8", "1"};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheckOneHash, VALID_INPUT9) {
    OneHashValidator check = OneHashValidator();
    std::string url = "64 1 1 1 1 1 1";
    std::vector<std::string> expected = {"64", "1"};
    EXPECT_EQ(check.validationCheck(url), expected);
}