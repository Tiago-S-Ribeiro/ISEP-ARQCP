#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h> 
#include <string.h> 
#include "asm.h"   	
short  * ptrvec;  
int num; 
short x;  
 short * call_func(short *  (*f)()); 
}

//START: testGroup
TEST_GROUP(vec_search)
{
    short  test_vec[100];
    short *   expected;
    void setup()
    {
        memset(test_vec, 0xaa, sizeof test_vec);
        expected = NULL; 
	ptrvec=test_vec; 
    }
    void teardown()
    {
    }
    void expect(short * addr )
    {
        expected = addr;
    }
    void given(short * vec, int num_elem,  short elem_to_search)
    { 
	short*  result; 
	memcpy(test_vec,vec,num_elem*sizeof(short)); 
	x=elem_to_search; 
	num=num_elem; 
	result=call_func(vec_search); 
        POINTERS_EQUAL(expected, result);
        BYTES_EQUAL(0xaa, test_vec[num_elem]& 0xff);
    }
};
//END: testGroup

TEST(vec_search, NullVector)
{
    expect(NULL); 
    short v[]={0}; 
    given(v,0,0);
}

TEST(vec_search, One)
{
    expect(&test_vec[0]);
    short v[]={1}; 
    given(v,1,1);
}


TEST(vec_search,Zero)
{
    expect(&test_vec[1]);
    short v[]={1,0,-1}; 
    given(v,3,0);
}


TEST(vec_search,MinusThree)
{
    expect(&test_vec[3]);
    short v[]={-1,-1,-1,-3}; 
    given(v,4,-3);
}

TEST(vec_search,Ten)
{
    expect(&test_vec[8]);
    short v[]={1,1,1,1,1,1,1,1,10}; 
    given(v,9,10);
}


TEST(vec_search,None)
{
    expect(NULL);
    short v[]={1,1,1,1,1,1,1,1,10}; 
    given(v,9,100);
}

