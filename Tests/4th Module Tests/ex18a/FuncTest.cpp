#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h> 
#include <string.h> 
#include "asm.h"    
int call_func(int (*f)(char *, int ), int p_param,  char*, int ); 

}

//START: testGroup
TEST_GROUP(sum_multiples_x)
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
    void given(char  p[] ,  int  num )
    { 
	int result; 
	result=call_func(sum_multiples_x,2,(char*)p,num); 
        LONGS_EQUAL(expected, result);
    }
};
//END: testGroup

TEST(sum_multiples_x, Zero)
{
    expect(0); 
    char v[]={0}; 
    given(v,0);
}



TEST(sum_multiples_x, One)
{
    expect(1); 
    char v[]={1,0}; 
    given(v,0x100);
}  


TEST(sum_multiples_x, OneA)
{
    expect(2); 
    char v[]={1,1,0}; 
    given(v,0x100);
}  


TEST(sum_multiples_x, OneB)
{
    expect(15); 
    char v[]={3,5,11,12,7,4,0}; 
    given(v,0xf0301);
} 


TEST(sum_multiples_x,Three) 
{
    expect(30); 
    char v[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,0}; 
    given(v,0xfff0500);
} 


TEST(sum_multiples_x,ThreeB) 
{
    expect(40); 
    char v[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,0}; 
    given(v,0x400);
}  
