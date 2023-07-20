//
// Created by Jannik Loth on 16.07.23.
//

#include "gtest/gtest.h"
#include "../src/Utilities.hpp"


// simple expected test
TEST(test1, getStarted)
{
    EXPECT_EQ(true, false);
    EXPECT_EQ(true, true);

//    EXPECT_EQ(Utilities::parseModeToString(Utilities::ParseMode::PREFIX), "prefix");
//    EXPECT_EQ(Utilities::parseModeToString(Utilities::ParseMode::INFIX), "infix");
//    EXPECT_EQ(Utilities::parseModeToString(Utilities::ParseMode::POSTFIX), "postfix");
}
