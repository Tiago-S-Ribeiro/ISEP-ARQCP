#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h> 
#include <string.h> 
#include "asm.h"    
int call_func(int (*f)(int *, int  ), int p_param, int  * , int ); 
}

//START: testGroup
TEST_GROUP(activate_2bits)
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
    void expect(int num )
    {
	expected_num=num; 
    }
    void given(int x ,int y )
    { 
	// int result; 
	int num_to_change=y; 
	call_func(activate_2bits,2,&num_to_change,x); 
	LONGS_EQUAL(expected_num,num_to_change);  
    }
};
//END: testGroup

TEST(activate_2bits, Zero)
{
    expect(0x80000001);	// result , changed number 
    given(0,0);		// bit to change, number to change  
}

TEST(activate_2bits, One)
{
    expect(0x88000011);
    given(4,0x80000001);
}


TEST(activate_2bits, Four)
{
    expect(0x88000011);
    given(4,0x88000011);
}


TEST(activate_2bits, Twelve)
{
    expect(0x88081011);
    given(12,0x88000011);
}

TEST(activate_2bits, TwelveA)
{
    expect(0x88081011);
    given(12,0x88081011);
}

