#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h> 
#include <string.h> 
#include "asm.h"   	
int  * ptrvec;  
int num; 

 int call_func(int (*f)()); 
}

//START: testGroup
TEST_GROUP(sum_first_byte)
{
    int test_vec[100];
    int  expected;
    void setup()
    {
        memset(test_vec, 0xaa, sizeof test_vec);
        expected = 0; 
	ptrvec=test_vec; 
    }
    void teardown()
    {
    }
    void expect(int num )
    {
        expected = num;
    }
    void given(int * vec, int num_elem)
    { 
	int result; 
	memcpy(test_vec,vec,num_elem*sizeof(int)); 
	num=num_elem; 
	result=call_func(sum_first_byte); 
        LONGS_EQUAL(expected, result);
        BYTES_EQUAL(0xaa, test_vec[num_elem]& 0xff);
    }
};
//END: testGroup

TEST(sum_first_byte, NullVector)
{
    expect(0); 
    int v[]={0}; 
    given(v,0);
}

TEST(sum_first_byte, One)
{
    expect(1);
    int v[]={1}; 
    given(v,1);
}


TEST(sum_first_byte,Zero)
{
    expect(0);
    int v[]={1,0,-1}; 
    given(v,3);
}


TEST(sum_first_byte,MinusThree)
{
    expect(-3);
    int v[]={-1,-1,-1}; 
    given(v,3);
}

TEST(sum_first_byte,HardTest)
{
    expect(508);
    int v[]={127,127,127,127}; 
    given(v,4);
}

TEST(sum_first_byte,Ten)
{
    expect(-38);
    int v[]={1,1,1,1,1,1,1,1,2002}; 
    given(v,9);
}





