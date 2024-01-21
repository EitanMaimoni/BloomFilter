#include <gtest/gtest.h>
#include "../src/commandValidator.h"
#include <vector>

TEST(SanityCheck, VALID_INPUT) {
    commandValidator check = commandValidator();
    std::string url = "a s";
    std::vector<string> expected = {};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheck, VALID_INPUT1) {
    commandValidator check = commandValidator();
    std::string url = "4 5 6";
    std::vector<string> expected = {};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheck, VALID_INPUT2) {
    commandValidator check = commandValidator();
    std::string url = "1 www.example.com";
    std::vector<string> expected = {"1", "www.example.com"};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheck, VALID_INPUT3) {
    commandValidator check = commandValidator();
    std::string url = "2 www.exmaple.com1";
    std::vector<string> expected = {"2","www.example.com1"};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheck, VALID_INPUT4) {
    commandValidator check = commandValidator();
    std::string url = "1 zzzz 7 6";
    std::vector<string> expected = {"1","zzz"};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheck, VALID_INPUT5) {
    commandValidator check = commandValidator();
    std::string url = "1 test.com 7 65 vtt";
    std::vector<string> expected = {"1","test.com"};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheck, VALID_INPUT7) {
    commandValidator check = commandValidator();
    std::string url = "3 tytyt";
    std::vector<int> expected = {"3","tytyt"};
    EXPECT_EQ(check.validationCheck(url), expected);
}

TEST(SanityCheck, VALID_INPUT8) {
    commandValidator check = commandValidator();
    std::string url = "2 anothertest.com";
    std::vector<int> expected = {"2","anothertest.com"};
    EXPECT_EQ(check.validationCheck(url), expected);
}

