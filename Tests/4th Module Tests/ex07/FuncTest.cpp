#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h> 
#include <string.h> 
#include "asm.h"   
int call_func(int (*f)(short *, int ), int p_param, short * p , int  num); 
}

//START: testGroup
TEST_GROUP(count_even)
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
    void given(short  p[] ,  int  num )
    { 
	int result; 
	result=call_func(count_even,2,(short*)p,num); 
        LONGS_EQUAL(expected, result);
    }
};
//END: testGroup

TEST(count_even, Zero)
{
    expect(0); 
    short v[]={}; 
    given(v,0);
}



TEST(count_even, One)
{
    expect(0); 
    short v[]={1}; 
    given(v,1);
}  


TEST(count_even, OneA)
{
    expect(1); 
    short v[]={0}; 
    given(v,1);
}  


TEST(count_even, OneB)
{
    expect(0); 
    short v[]={-1}; 
    given(v,1);
} 


TEST(count_even,Three) 
{
    expect(1); 
    short v[]={1,2,3}; 
    given(v,3);
} 


TEST(count_even,ThreeB) 
{
    expect(3); 
    short v[]={1,2,3,4,5,6}; 
    given(v,6);
}  
