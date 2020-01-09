#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h> 
#include <string.h> 
#include "asm.h"    
int call_func(int (*f)(int , int , int  ), int p_param, int ,int , int); 
}

//START: testGroup
TEST_GROUP(mixed_sum)
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
    void given(int x ,int y ,int z)
    { 
	int result; 
	result=call_func(mixed_sum,3,x,y,z); 
        LONGS_EQUAL(expected, result);
    }
};
//END: testGroup

TEST(mixed_sum, One)
{
    expect(-1);
    given(0,-1,8);
}

TEST(mixed_sum, Two)
{
    expect(0xfffffffe);
    given(-1,-1,8);
}

TEST(mixed_sum, Three)
{
    expect(1);
    given(0,1,0);
}
TEST(mixed_sum,Four)
{
    expect(1);
    given(1,0,0);
}

TEST(mixed_sum, Five)
{
    expect(0xe);
    given(-1,15,31);
}

TEST(mixed_sum, Six)
{
    expect(0xe);
    given(15,-1,31);
}


TEST(mixed_sum, Seven)
{
    expect(0);
    given(-1,1,15);
}


TEST(mixed_sum, Eight)
{
    expect(0);
    given(1,-1,15);
}

