#include <gtest/gtest.h>
#include "../src/main.h" // here we include the code to be tested

TEST(SanityCheck, test1) {
    char* argv[] = {"128", "1\n", "1" "www.example.com\n"};
    int argc = sizeof(argv) / sizeof(char*);

    int result = main(argc, argv);

    ASSERT_EQ(result, true);
}

TEST(SanityCheck, test2) {
    char* argv[] = {"128", "2", "1\n", "2", "www.example.com\n"};
    int argc = sizeof(argv) / sizeof(char*);

    int result = main(argc, argv);

    ASSERT_EQ(result, true);
}
