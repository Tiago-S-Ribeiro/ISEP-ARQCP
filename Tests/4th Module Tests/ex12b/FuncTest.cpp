#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h> 
#include <string.h> 
#include "asm.h"    
int call_func(int (*f)(int *, int ), int p_param, int * , int ); 
}

//START: testGroup
TEST_GROUP(activate_bit)
{
    int  expected;  
    int  expected_num; 

    void setup()
    {
        expected =0;  
	expected_num=0; 
    }
    void teardown()
    {
    }
    void expect(int num ,int num2)
    {
        expected = num; 
	expected_num=num2; 
    }
    void given(int x ,int y )
    { 
	int result; 
	int num_to_change=y; 
	result=call_func(activate_bit,2,&num_to_change,x); 
        LONGS_EQUAL(expected, result);
	LONGS_EQUAL(expected_num,num_to_change);  
    }
};
//END: testGroup

TEST(activate_bit, Zero)
{
    expect(1,1);	// result , changed number 
    given(0,0);		// bit to change, number to change  
}

TEST(activate_bit, One)
{
    expect(0,1);
    given(0,1);
}


TEST(activate_bit, Four)
{
    expect(1,0x11);
    given(4,1);
}


TEST(activate_bit, FourA)
{
    expect(0,0x11);
    given(4,0x11);
}



TEST(activate_bit, Twelve)
{
    expect(1,0x1011);
    given(12,0x11);
}


TEST(activate_bit, TwelveA)
{
    expect(0,0x1011);
    given(12,0x1011);
}



