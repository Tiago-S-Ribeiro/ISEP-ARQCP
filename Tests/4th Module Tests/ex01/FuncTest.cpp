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
TEST_GROUP(cube)
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
	result=call_func(cube,1,x); 
        LONGS_EQUAL(expected, result);
    }
};
//END: testGroup

TEST(cube, Zero)
{
    expect(0);
    given(0);
}

TEST(cube, One)
{
    expect(1);
    given(1);
}


TEST(cube, MinusOne)
{
    expect(-1);
    given(-1);
}

TEST(cube,Two)
{
    expect(8);
    given(2);
}

TEST(cube, MinusThree)
{
    expect(-27);
    given(-3);
}



TEST(cube, Five)
{
    expect(125);
    given(5);
}
