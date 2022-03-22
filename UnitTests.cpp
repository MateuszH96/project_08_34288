#include <gtest/gtest.h>
#include "header/ReadFile.h"
#include <iostream>
TEST(ReadFileTest, GetCorrectString)
{
    Read *stringTest = new ReadFile("../UnitTests/UnitTestFile.txt");
    std::string correctResult1="1\n12\n123\n";
    std::string correctResult2="123";

    ASSERT_EQ(correctResult1, stringTest->getStringFromFile(Flag::ALL_LINES));
    ASSERT_EQ(correctResult2, stringTest->getStringFromFile(Flag::ONE_LINE,3));

}

int main(int argc, char **argv) 
{
    testing::InitGoogleTest(&argc, argv);  
    return RUN_ALL_TESTS();
}