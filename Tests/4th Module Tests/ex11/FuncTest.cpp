#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h> 
#include <string.h> 
#include "asm.h"    

int call_func(int (*f)(int , int ), int p_param, int , int ) ; 
}

//START: testGroup
TEST_GROUP(rotate_left)
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
    void given(int x , int y)
    { 
	int result; 
	result=call_func(rotate_left,2,x,y); 
        LONGS_EQUAL(expected, result);
    }
};
//END: testGroup

TEST(rotate_left, Zero)
{
    expect(0);
    given(0,0);
}

TEST(rotate_left, ZeroB)
{
    expect(0);
    given(0,10);
}

TEST(rotate_left, One)
{
    expect(4);
    given(1,2);
}


TEST(rotate_left, MinusOne)
{
    expect(-1);
    given(-1,10);
}

TEST(rotate_left,Seven)
{
    expect(7);
    given(0x70000000,4);
}

TEST(rotate_left, Fives)
{
    expect(0xaaaaaaaa);
    given(0x55555555,1);
}


//START: testGroup
TEST_GROUP(rotate_right)
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
    void given(int x , int y)
    { 
	int result; 
	result=call_func(rotate_right,2,x,y); 
        LONGS_EQUAL(expected, result);
    }
};
//END: testGroup

TEST(rotate_right, Zero)
{
    expect(0);
    given(0,0);
}

TEST(rotate_right, ZeroB)
{
    expect(0);
    given(0,10);
}

TEST(rotate_right, One)
{
    expect(1);
    given(4,2);
}


TEST(rotate_right, MinusOne)
{
    expect(-1);
    given(-1,10);
}

TEST(rotate_right,Seven)
{
    expect(0x70000000);
    given(0x7,4);
}

TEST(rotate_right, Fives)
{
    expect(0xaaaaaaaa);
    given(0x55555555,1);
}

