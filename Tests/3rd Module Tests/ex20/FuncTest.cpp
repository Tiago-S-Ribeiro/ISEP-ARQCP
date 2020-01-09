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
TEST_GROUP(count_seq)
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
	result=call_func(count_seq); 
        LONGS_EQUAL(expected, result);
        BYTES_EQUAL(0xaa, test_vec[num_elem]& 0xff);
    }
};
//END: testGroup

TEST(count_seq, NullVector)
{
    expect(0); 
    int v[]={0}; 
    given(v,0);
}

TEST(count_seq, Zero)
{
    expect(0);
    int v[]={1}; 
    given(v,1);
}


TEST(count_seq,One)
{
    expect(1);
    int v[]={-1,0,1}; 
    given(v,3);
}


TEST(count_seq,MinusThree)
{
    expect(0);
    int v[]={-1,-1,-1}; 
    given(v,3);
}

TEST(count_seq,Ten)
{
    expect(8);
    int v[]={1,2,3,4,5,6,7,8,9,10}; 
    given(v,10);
}





