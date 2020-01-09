#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h> 
#include <string.h> 
#include "asm.h"    
 int call_func(int (*f)(int, int * , int  ), int p_param, int , int * , int ); 
}

//START: testGroup
TEST_GROUP(calc)
{
    int  expected;  
    int  x1; 
    int  second;  
    int  x2; 
    void setup()
    {
        expected = 0;  
	second=0;  
	x1=0x55555555; 
	x2=0x55555555;  // check for "mad" pointer 
    }
    void teardown()
    {
    }
    void expect(int num )
    {
        expected = num;
    }
    void given(int x ,int y, int z) //  (y-x)*z 
    { 
	int result; 
	second=y; 
	result=call_func(calc,3,x,&second,z); 
        LONGS_EQUAL(expected, result);
        LONGS_EQUAL(0x55555555, x1);
        LONGS_EQUAL(0x55555555, x2);
    }
};
//END: testGroup

TEST(calc, MinusTwo)
{
    expect(-2);
    given(0,0,0);
}

TEST(calc, MinusOnea)
{
    expect(-1);
    given(1,2,1);
}

TEST(calc, MinusThree)
{
    expect(-3);
    given(2,1,1);
}

TEST(calc, MinusOne)
{
    expect(-1);
    given(2,1,-1);
}


TEST(calc, MinusSix)
{
    expect(-6);
    given(2,1,4);
}



TEST(calc, Six)
{
    expect(6);
    given(3,1,-4);
}
