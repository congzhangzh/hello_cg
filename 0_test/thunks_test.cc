#include <common/thunks.hpp>
#include <gtest/gtest.h>


TEST(HelloWorld, Test)
{
    EXPECT_EQ(1, 1);
}


class DemoTrunk
{
public:
    int add(int a, int b)
    {
        return a + b;
    }
};

TEST(thrunk_Test, simple_member_func)
{
    DemoTrunk dt;
    lunaticpp::thunk<&DemoTrunk::add> thunk(&dt);

    auto add=thunk.func();
    auto result=add(1,2);
    EXPECT_EQ(result, 3);
}

TEST(thrunk_Test, std_func_test)
{
    std::function<int(int, int)> f=[](int a, int b){return a+b;};
    lunaticpp::thunk<&std::function<int(int, int)>::operator ()> thunk(&f);

    auto add=thunk.func();
    auto result=add(1,2);
    EXPECT_EQ(result, 3);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
