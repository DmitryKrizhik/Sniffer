#include "gtest/gtest.h"
#include "App.h"


TEST(AppSuiteException, ThrowException)
{

    EXPECT_THROW(App::IPv4Check(App::interfaceIPAddr, NULL), std::runtime_error);
    std::cout << "EXPECT_THROW 1 - DONE" << std::endl;

    EXPECT_THROW(App::IP_Check("10.0.0.0"), std::logic_error);
    std::cout << "EXPECT_THROW 2 - DONE" << std::endl;

    EXPECT_THROW(App::IP_Check("100.64.0.0"), std::logic_error);
    std::cout << "EXPECT_THROW 3 - DONE" << std::endl;

    EXPECT_THROW(App::IP_Check("172.16.0.0"), std::logic_error);
    std::cout << "EXPECT_THROW 4 - DONE" << std::endl;

    EXPECT_THROW(App::IP_Check("192.168.0.0"), std::logic_error);
    std::cout << "EXPECT_THROW 5 - DONE" << std::endl;

}

TEST(AppAssertion, AssertionCheck)
{

    size_t TimerBeforeClassObjInitialization = App::GetTimer();
    App App(10, "10.0.2.15");
    size_t TimerAfterClassObjInitialization = App::GetTimer();


    EXPECT_EQ(TimerBeforeClassObjInitialization, 0);
    std::cout << "EXPECT_EQ 1 - DONE" << std::endl;

    EXPECT_GE(TimerAfterClassObjInitialization, 10);
    std::cout << "EXPECT_GT 1 - DONE" << std::endl;

}

int main()
{
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}








    
