#include <iostream>
#include "FileHandler.hpp"
#include "gtest_lite.h"


void Test() {
    TEST(StartMenu, "no file") {
        EXPECT_ANY_THROW(loadFile());
    } END;
    TEST(StartMenu, "file included") {
        EXPECT_NO_THROW(loadFile("state.txt"));
    } END;
}