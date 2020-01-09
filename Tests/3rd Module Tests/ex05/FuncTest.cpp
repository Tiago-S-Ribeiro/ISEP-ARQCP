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
TEST_GROUP(vec_sum)
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
	result=call_func(vec_sum); 
        LONGS_EQUAL(expected, result);
        BYTES_EQUAL(0xaa, test_vec[num_elem]& 0xff);
    }
};
//END: testGroup

TEST(vec_sum, NullVector)
{
    expect(0); 
    int v[]={0}; 
    given(v,0);
}

TEST(vec_sum, One)
{
    expect(1);
    int v[]={1}; 
    given(v,1);
}


TEST(vec_sum,Zero)
{
    expect(0);
    int v[]={1,0,-1}; 
    given(v,3);
}


TEST(vec_sum,MinusThree)
{
    expect(-3);
    int v[]={-1,-1,-1}; 
    given(v,3);
}

TEST(vec_sum,Ten)
{
    expect(2010);
    int v[]={1,1,1,1,1,1,1,1,2002}; 
    given(v,9);
}



//START: testGroup
TEST_GROUP(vec_avg)
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
	result=call_func(vec_avg); 
        LONGS_EQUAL(expected, result);
        BYTES_EQUAL(0xaa, test_vec[num_elem]& 0xff);
    }
};
//END: testGroup


TEST(vec_avg, NullVector)
{
    expect(0); 
    int v[]={0}; 
    given(v,0);
}

TEST(vec_avg, One)
{
    expect(1);
    int v[]={1}; 
    given(v,1);
}


TEST(vec_avg,Zero)
{
    expect(0);
    int v[]={1,0,1}; 
    given(v,3);
}


TEST(vec_avg,MinusThree)
{
    expect(-3);
    int v[]={-3,-3,-3}; 
    given(v,3);
}

TEST(vec_avg,Ten)
{
    expect(10);
    int v[]={10,10,10,10,10,10,10,10,10,10}; 
    given(v,10);
}




