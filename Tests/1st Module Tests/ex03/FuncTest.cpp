#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h> 
#include <string.h> 
#include "asm.h"   	
int  * ptrvec;  
int num; 
}

//START: testGroup
TEST_GROUP(sum_even)
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
	 
	result=sum_even(vec,num_elem); 
        LONGS_EQUAL(expected, result);
        BYTES_EQUAL(0xaa, test_vec[num_elem]& 0xff);
    }
};
//END: testGroup

TEST(sum_even, NullVector)
{
    expect(0); 
    int v[]={0}; 
    given(v,0);
}

TEST(sum_even, One)
{
    expect(0);
    int v[]={1}; 
    given(v,1);
}


TEST(sum_even,Zero)
{
    expect(0);
    int v[]={1,0,-1}; 
    given(v,3);
}


TEST(sum_even,MinusThree)
{
    expect(0);
    int v[]={-1,-1,-1}; 
    given(v,3);
}

TEST(sum_even,Ten)
{
    expect(20);
    int v[]={1,1,1,1,18,1,1,1,2}; 
    given(v,9);
}





