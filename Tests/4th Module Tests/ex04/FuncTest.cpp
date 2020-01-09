#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h> 
#include <string.h> 
#include "asm.h"   
int call_func(int (*f)(int, int, int *  ), int p_param, int x, int y , int *p ); 
}

//START: testGroup
TEST_GROUP(sum_smaller)
{
    int  expected;  
    int  expected_s; 

    void setup()
    {
        expected = 0;  
	expected_s=0; 
    }
    void teardown()
    {
    }
    void expect(int num ,int smaller)
    {
        expected = num; 
	expected_s=smaller; 
    }
    void given(int x ,int y )
    { 
	int result; 
	int minor; 
	result=call_func(sum_smaller,3,x,y,&minor); 
        LONGS_EQUAL(expected, result);
	LONGS_EQUAL(expected_s,minor) 
    }
};
//END: testGroup

TEST(sum_smaller, Zero)
{
    expect(0,0);
    given(0,0);
}

TEST(sum_smaller, One)
{
    expect(1,0);
    given(0,1);
}


TEST(sum_smaller, MinusOne)
{
    expect(-3,-2);
    given(-2,-1);
}

TEST(sum_smaller, MinusOneB)
{
    expect(-5,-3);
    given(-3,-2);
}
TEST(sum_smaller,Two)
{
    expect(6,2);
    given(4,2);
}

TEST(sum_smaller, Three)
{
    expect(9,3);
    given(6,3);
}



TEST(sum_smaller, Five)
{
    expect(110,5);
    given(105,5);
}
