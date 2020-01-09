#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h> 
#include <string.h> 
#include "asm.h"    

int call_func(int (*f)(int, int,  int ), int p_param, int x, int y , int z ); 
}

//START: testGroup
TEST_GROUP(greatest)
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
	result=call_func(greatest,3,x,y,z); 
        LONGS_EQUAL(expected, result);
    }
};
//END: testGroup

TEST(greatest, Zero)
{
    expect(0);
    given(0,0,0);
}

TEST(greatest, One)
{
    expect(1);
    given(0,1,-1);
}


TEST(greatest, MinusOne)
{
    expect(-1);
    given(-1,-2,-3);
}

TEST(greatest, MinusOneB)
{
    expect(-1);
    given(-3,-2,-1);
}
TEST(greatest,Two)
{
    expect(2);
    given(0,2,1);
}

TEST(greatest, Three)
{
    expect(3);
    given(2,3,2);
}



TEST(greatest, Five)
{
    expect(5);
    given(-200,3,5);
}
