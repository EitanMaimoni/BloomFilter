#include <gtest/gtest.h>
#include "../src/commandValidator.h"
#include <vector>

TEST(SanityCheckCommand, VALID_INPUT) {
    commandValidator check = commandValidator();
    std::string url = "a s";
    std::vector<std::string> expected = {};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheckCommand, VALID_INPUT1) {
    commandValidator check = commandValidator();
    std::string url = "4 5 6";
    std::vector<std::string> expected = {};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheckCommand, VALID_INPUT2) {
    commandValidator check = commandValidator();
    std::string url = "1 www.example.com";
    std::vector<std::string> expected = {"1", "www.example.com"};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheckCommand, VALID_INPUT3) {
    commandValidator check = commandValidator();
    std::string url = "2 www.example.com1";
    std::vector<std::string> expected = {"2","www.example.com1"};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheckCommand, VALID_INPUT4) {
    commandValidator check = commandValidator();
    std::string url = "1 zzzz 7 6";
    std::vector<std::string> expected = {"1","zzzz"};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheckCommand, VALID_INPUT5) {
    commandValidator check = commandValidator();
    std::string url = "1 test.com 7 65 vtt";
    std::vector<std::string> expected = {"1","test.com"};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheckCommand, VALID_INPUT7) {
    commandValidator check = commandValidator();
    std::string url = "3 tytyt";
    std::vector<std::string> expected = {};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheckCommand, VALID_INPUT8) {
    commandValidator check = commandValidator();
    std::string url = "2 anothertest.com";
    std::vector<std::string> expected = {"2","anothertest.com"};
    EXPECT_EQ(check.validationCheck(url), expected);
}

