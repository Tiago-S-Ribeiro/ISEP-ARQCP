#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h> 
#include <string.h> 
#include "asm.h"   	
int  * ptrvec;  
int num; 
int even;   
 int call_func(int (*f)()); 
}

//START: testGroup
TEST_GROUP(vec_sum_even)
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
	result=call_func(vec_sum_even); 
        LONGS_EQUAL(expected, result);
        BYTES_EQUAL(0xaa, test_vec[num_elem]& 0xff);
    }
};
//END: testGroup

TEST(vec_sum_even, NullVector)
{
    expect(0); 
    int v[]={0}; 
    given(v,0);
}

TEST(vec_sum_even, One)
{
    expect(0);
    int v[]={1}; 
    given(v,1);
}


TEST(vec_sum_even,Zero)
{
    expect(0);
    int v[]={1,0,-1}; 
    given(v,3);
}


TEST(vec_sum_even,MinusTwo)
{
    expect(-2);
    int v[]={-4,-1,2}; 
    given(v,3);
}

TEST(vec_sum_even,Ten)
{
    expect(10);
    int v[]={2,1,1,2,1,1,2,2,2}; 
    given(v,9);
}



//START: testGroup
TEST_GROUP(test_even)
{
    int  expected;
    void setup()
    {
    }
    void teardown()
    {
    }
    void expect(int num )
    {
        expected = num;
    }
    void given(int num_to_test)
    { 
	int result; 
	even=num_to_test; 
	result=call_func(test_even); 
        LONGS_EQUAL(expected, result);
    }
};
//END: testGroup


TEST(test_even, Zero)
{
    expect(1); 
    given(0);
}

TEST(test_even, One)
{
    expect(0);
    given(1);
}


TEST(test_even,MinusOne)
{
    expect(0);
    given(-1);
}


TEST(test_even,MinusThree)
{
    expect(0);
    given(3);
}

TEST(test_even,Ten)
{
    expect(1);
    given(10);
}




