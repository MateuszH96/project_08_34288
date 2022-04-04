#include <gtest/gtest.h>
#include "../header/ReadFile.h"
#include "../header/MenuPos.h"
TEST(ReadFileTest, GetCorrectString)
{
    Read *stringTest = new ReadFile("../UnitTestFile.txt");
    std::string correctResult1="1\n12\n123\n";
    std::string correctResult2="123";

    ASSERT_EQ(correctResult1, stringTest->getStringFromFile(Flag::ALL_LINES));
    ASSERT_EQ(correctResult2, stringTest->getStringFromFile(Flag::ONE_LINE,3));

}

TEST(MenuPosTest, SplitString)
{
    MenuPos tmp("1,Pieczarki,2.00,2.50,3.50");
    ASSERT_EQ(1,tmp.getId());
    ASSERT_EQ("Pieczarki",tmp.getName());
    ASSERT_EQ(2.00,tmp.getSmallSize());
    ASSERT_EQ(2.50,tmp.getMediumSize());
    ASSERT_EQ(3.50,tmp.getLargeSize());
}

int main(int argc, char **argv) 
{
    testing::InitGoogleTest(&argc, argv);  
    return RUN_ALL_TESTS();
}