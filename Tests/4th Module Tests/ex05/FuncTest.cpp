#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h> 
#include <string.h> 
#include "asm.h"   
int call_func(int (*f)(int * , int  ), int p_param, int * p, int num); 
}

//START: testGroup
TEST_GROUP(inc_square)
{
    int  expected;  
    int  expected_inc; 

    void setup()
    {
        expected =0;  
	expected_inc=0; 
    }
    void teardown()
    {
    }
    void expect(int num ,int num2)
    {
        expected = num; 
	expected_inc=num2; 
    }
    void given(int x ,int y )
    { 
	int result; 
        int wall1=0x12345678; 
	int num_to_inc=y; 
        int wall2=0x87654321; 
	result=call_func(inc_and_square,2,&num_to_inc,x); 
        LONGS_EQUAL(expected, result);
	LONGS_EQUAL(expected_inc,num_to_inc);  
	LONGS_EQUAL(0x12345678,wall1); 
        LONGS_EQUAL(0x87654321,wall2); 	
    }
};
//END: testGroup

TEST(inc_square, Zero)
{
    expect(0,2);	// square , incremented number 
    given(0,1);		// base, number to increment  
}

TEST(inc_square, One)
{
    expect(1,3);
    given(1,2);
}


TEST(inc_square, MinusOne)
{
    expect(1,0);
    given(-1,-1);
}

TEST(inc_square, MinusOneB)
{
    expect(1,-1);
    given(-1,-2);
}
TEST(inc_square,Two)
{
    expect(4,1);
    given(2,0);
}

TEST(inc_square, Three)
{
    expect(9,5);
    given(3,4);
}



TEST(inc_square, Five)
{
    expect(25,6);
    given(5,5);
}
