#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h> 
#include <string.h> 
#include "asm.h"    

int call_func(int (*f)(int ), int p_param, int num); 
}

//START: testGroup
TEST_GROUP(count_bits_zero)
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
    void given(int x )
    { 
	int result; 
	result=call_func(count_bits_zero,1,x); 
        LONGS_EQUAL(expected, result);
    }
};
//END: testGroup

TEST(count_bits_zero, None)
{
    expect(0);
    given(-1);
}

TEST(count_bits_zero, MinusTwo)
{
    expect(1);
    given(-2);
}


TEST(count_bits_zero,All)
{
    expect(32);
    given(0);
}

TEST(count_bits_zero, Three)
{
    expect(30);
    given(3);
}

TEST(count_bits_zero, Sixteen)
{
    expect(16);
    given(0xffff);
}


TEST(count_bits_zero, SixteenA)
{
    expect(16);
    given(0xffff0000);
}
TEST(count_bits_zero, SixteenB)
{
    expect(16);
    given(0x0f0f0f0f);
}

TEST(count_bits_zero, Sixteenc)
{
    expect(16);
    given(0xf0f0f0f0);
}
