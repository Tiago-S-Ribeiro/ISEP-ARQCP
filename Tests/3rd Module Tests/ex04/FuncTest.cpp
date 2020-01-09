#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h> 
#include <string.h> 
#include "asm.h"   	

void call_func(void (*f)()); 

int  * ptrvec;  
int num; 
}

//START: testGroup
TEST_GROUP(vec_add_one)
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
	call_func(vec_add_one); 
	MEMCMP_EQUAL(expected,test_vec,num_elem*sizeof(int)) ; 
        BYTES_EQUAL(0xaa, test_vec[num_elem]& 0xff);
    }
};
//END: testGroup

TEST(vec_add_one, NullVector)
{
    int e[]={0}; 
    expect(e); 
    int v[]={0}; 
    given(v,0);
}

TEST(vec_add_one, One)
{
    int e[]={2}; 
    expect(e);
    int v[]={1}; 
    given(v,1);
}


TEST(vec_add_one,Zero)
{
    int e[]={2,1,0}; 
    expect(e);
    int v[]={1,0,-1}; 
    given(v,3);
}


TEST(vec_add_one,MinusThree)
{
    int e[]={-1,-1,-1}; 
    expect(e);
    int v[]={-2,-2,-2}; 
    given(v,3);
}

TEST(vec_add_one,Ten)
{
    int e[]={2,2,2,2,2,2,2,2,256}; 
    expect(e);
    int v[]={1,1,1,1,1,1,1,1,255}; 
    given(v,9);
}




