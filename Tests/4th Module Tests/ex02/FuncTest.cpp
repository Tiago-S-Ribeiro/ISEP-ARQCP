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
TEST_GROUP(sum_n)
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
	result=call_func(sum_n,1,x); 
        LONGS_EQUAL(expected, result);
    }
};
//END: testGroup

TEST(sum_n, Zero)
{
    expect(0);
    given(0);
}

TEST(sum_n, One)
{
    expect(1);
    given(1);
}


TEST(sum_n, MinusOne)
{
    expect(0);
    given(-1);
}

TEST(sum_n,Two)
{
    expect(3);
    given(2);
}

TEST(sum_n, Three)
{
    expect(6);
    given(3);
}



TEST(sum_n, Five)
{
    expect(15);
    given(5);
}
