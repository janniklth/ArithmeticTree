//
// Created by Jannik Loth on 17.07.23.
//

#include "gtest/gtest.h"
#include "../src/Utilities.hpp"

TEST(UtilitiesTest, parseModeToString)
{
    EXPECT_EQ(Utilities::parseModeToString(Utilities::ParseMode::PREFIX), "PREFIX");
    EXPECT_EQ(Utilities::parseModeToString(Utilities::ParseMode::INFIX), "INFIX");
    EXPECT_EQ(Utilities::parseModeToString(Utilities::ParseMode::POSTFIX), "POSTFIX");
}
