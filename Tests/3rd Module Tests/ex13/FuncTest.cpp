#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h> 
#include <string.h> 
#include "asm.h"   	
int  * ptrvec;  
int num; 
 void call_func(void (*f)()); 
}

//START: testGroup
TEST_GROUP(keep_positives)
{
    int test_vec[100];
    int *expected;
    void setup()
    {
        memset(test_vec, 0xaa, sizeof test_vec);
        expected = NULL; 
	ptrvec=test_vec; 
    }
    void teardown()
    {
    }
    void expect(int * exp)
    {
        expected = exp;
    }
    void given(int * vec, int num_elem)
    { 
	memcpy(test_vec,vec,num_elem*sizeof(int)); 
	num=num_elem; 
	call_func(keep_positives); 
	MEMCMP_EQUAL(expected,test_vec,num_elem*sizeof(int)) ; 
        BYTES_EQUAL(0xaa, test_vec[num_elem]& 0xff);
    }
};
//END: testGroup

TEST(keep_positives, NullVector)
{
    int e[]={0}; 
    expect(e); 
    int v[]={0}; 
    given(v,0);
}

TEST(keep_positives, One)
{
    int e[]={0}; 
    expect(e);
    int v[]={0}; 
    given(v,1);
}


TEST(keep_positives,Zero)
{
    int e[]={0,0,2}; 
    expect(e);
    int v[]={-1,0,2}; 
    given(v,3);
}


TEST(keep_positives,MinusThree)
{
    int e[]={0,1,2}; 
    expect(e);
    int v[]={-1,-1,-1}; 
    given(v,3);
}

TEST(keep_positives,Ten)
{
    int e[]={0,1,2,3,4,5,6,7,8}; 
    expect(e);
    int v[]={0,1,2,3,4,5,6,7,-2}; 
    given(v,9);
}




