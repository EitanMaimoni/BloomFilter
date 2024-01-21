#include <gtest/gtest.h>
#include "../src/iValidator.h"
#include "../src/oneHashValidator.h"
#include <vector>

TEST(SanityCheckOneHash, VALID_INPUT1) {
    oneHashValidator check = oneHashValidator();
    std::string url = "8 1";
    std::vector<std::string> expected = {"8", "1"};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheckOneHash, VALID_INPUT2) {
    oneHashValidator check = oneHashValidator();
    std::string url = "64 1";
    std::vector<std::string> expected = {"64", "1"};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheckOneHash, VALID_INPUT3) {
    oneHashValidator check = oneHashValidator();
    std::string url = "x y z";
    std::vector<std::string> expected = {};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheckOneHash, VALID_INPUT4) {
    oneHashValidator check = oneHashValidator();
    std::string url = "8 x 1";
    std::vector<std::string> expected = {};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheckOneHash, VALID_INPUT5) {
    oneHashValidator check = oneHashValidator();
    std::string url = "z";
    std::vector<std::string> expected = {};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheckOneHash, VALID_INPUT6) {
    oneHashValidator check = oneHashValidator();
    std::string url = "64";
    std::vector<std::string> expected = {};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheckOneHash, VALID_INPUT7) {
    oneHashValidator check = oneHashValidator();
    std::string url = "x 1 2";
    std::vector<std::string> expected = {};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheckOneHash, VALID_INPUT8) {
    oneHashValidator check = oneHashValidator();
    std::string url = "8 1 x c v v";
    std::vector<std::string> expected = {"8", "1"};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheckOneHash, VALID_INPUT9) {
    oneHashValidator check = oneHashValidator();
    std::string url = "64 1 1 1 1 1 1";
    std::vector<std::string> expected = {"64", "1"};
    EXPECT_EQ(check.validationCheck(url), expected);
}