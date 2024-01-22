#include <gtest/gtest.h>
#include "../src/CommandValidator.h"
#include <vector>

TEST(SanityCheckCommand, VALID_INPUT) {
    CommandValidator check = CommandValidator();
    std::string url = "a s";
    std::vector<std::string> expected = {};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheckCommand, VALID_INPUT1) {
    CommandValidator check = CommandValidator();
    std::string url = "4 5 6";
    std::vector<std::string> expected = {};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheckCommand, VALID_INPUT2) {
    CommandValidator check = CommandValidator();
    std::string url = "1 www.example.com";
    std::vector<std::string> expected = {"1", "www.example.com"};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheckCommand, VALID_INPUT3) {
    CommandValidator check = CommandValidator();
    std::string url = "2 www.example.com1";
    std::vector<std::string> expected = {"2","www.example.com1"};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheckCommand, VALID_INPUT4) {
    CommandValidator check = CommandValidator();
    std::string url = "1 zzzz 7 6";
    std::vector<std::string> expected = {"1","zzzz"};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheckCommand, VALID_INPUT5) {
    CommandValidator check = CommandValidator();
    std::string url = "1 test.com 7 65 vtt";
    std::vector<std::string> expected = {"1","test.com"};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheckCommand, VALID_INPUT7) {
    CommandValidator check = CommandValidator();
    std::string url = "3 tytyt";
    std::vector<std::string> expected = {};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheckCommand, VALID_INPUT8) {
    CommandValidator check = CommandValidator();
    std::string url = "2 anothertest.com";
    std::vector<std::string> expected = {"2","anothertest.com"};
    EXPECT_EQ(check.validationCheck(url), expected);
}

