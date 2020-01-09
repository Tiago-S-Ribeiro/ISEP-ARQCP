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
TEST_GROUP(odd_sum)
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
    void given(int * vec)
    { 
	int result; 
	memcpy(test_vec,vec,(vec[0]+1)*sizeof(int)); 
	 
	result=odd_sum(vec); 
        LONGS_EQUAL(expected, result);
        BYTES_EQUAL(0xaa, test_vec[vec[0]+1]& 0xff);
    }
};
//END: testGroup

TEST(odd_sum, NullVector)
{
    expect(0); 
    int v[]={0}; 
    given(v);
}

TEST(odd_sum, One)
{
    expect(1);
    int v[]={1,1}; 
    given(v);
}


TEST(odd_sum,Zero)
{
    expect(0);
    int v[]={2,1,-1}; 
    given(v);
}


TEST(odd_sum,MinusThree)
{
    expect(-2);
    int v[]={2,-1,-1}; 
    given(v);
}

TEST(odd_sum,Ten)
{
    expect(7);
    int v[]={9,1,1,1,1,18,1,1,1,2}; 
    given(v);
}





