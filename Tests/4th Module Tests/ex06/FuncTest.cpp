#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h> 
#include <string.h> 
#include "asm.h"    
int call_func(int (*f)(char *, char * ), int p_param,char * p1 , char *p2  ); 
}

//START: testGroup
TEST_GROUP(test_equal)
{
    int  expected;
    void setup()
    {
        expected = 0; 
    }
    void teardown()
    {
    }
    void expect(int num )
    {
        expected = num;
    }
    void given(const char  p1[] , const char  p2[])
    { 
	int result; 
	result=call_func(test_equal,2,(char*)p1,(char*)p2); 
        LONGS_EQUAL(expected, result);
    }
};
//END: testGroup

TEST(test_equal, Zero)
{
    expect(1);
    given("","");
}

TEST(test_equal, One)
{
    expect(1);
    given("1","1");
}

TEST(test_equal, OneA)
{
    expect(0);
    given("1","");
}

TEST(test_equal, OneB)
{
    expect(0);
    given("","1");
}

TEST(test_equal,Two)
{
    expect(1);
    given("ab","ab");
}


TEST(test_equal,TwoA)
{
    expect(0);
    given("a","ab");
}

TEST(test_equal,TwoB)
{
    expect(0);
    given("ab","a");
}
TEST(test_equal, Five)
{
    expect(1);
    given("abcde","abcde");
}


TEST(test_equal, FiveA)
{
    expect(0);
    given("abcdz","abcde");
}

TEST(test_equal, FiveB)
{
    expect(0);
    given("abcde","abcdz");
}

