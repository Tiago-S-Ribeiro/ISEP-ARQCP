#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h> 
#include <string.h> 
#include "asm.h"   	
int  * ptrsrc;  
int  * ptrdest;  
int num;  

int call_func(int (*f)()); 
}

//START: testGroup
TEST_GROUP(sort_without_reps)
{
    int test_vec[100]; 
    int out_vec[100]; 
	
    int *expected;
    int res; 

    void setup()
    {
        memset(test_vec, 0xaa, sizeof test_vec);
        memset(out_vec, 0xaa, sizeof out_vec);
        expected = NULL; 
	ptrsrc=test_vec;  
 	ptrdest=out_vec; 	
    }
    void teardown()
    {
    }
    void expect(int * exp,int result)
    {
        expected = exp;
	res=result; 
    }
    void given(int * vec, int num_elem)
    { 
	int r; 
	memcpy(test_vec,vec,num_elem*sizeof(int)); 
	num=num_elem; 
	r=call_func(sort_without_reps); 
	LONGS_EQUAL(res,r)
	MEMCMP_EQUAL(expected,out_vec,r*sizeof(int)) ; 
        BYTES_EQUAL(0xaa, test_vec[num_elem]& 0xff);
        BYTES_EQUAL(0xaa, out_vec[r]& 0xff);
    }
};
//END: testGroup

TEST(sort_without_reps, NullVector)
{
    int e[]={0}; 
    expect(e,0); 
    int v[]={0}; 
    given(v,0);
}

TEST(sort_without_reps, One)
{
    int e[]={1}; 
    expect(e,1);
    int v[]={1}; 
    given(v,1);
}


TEST(sort_without_reps,Zero)
{
    int e[]={0,1,2}; 
    expect(e,3);
    int v[]={2,0,1}; 
    given(v,3);
}


TEST(sort_without_reps,MinusThree)
{
    int e[]={-3,-2,-1}; 
    expect(e,3);
    int v[]={-1,-2,-3}; 
    given(v,3);
}

TEST(sort_without_reps,Ten)
{
    int e[]={1,2}; 
    expect(e,2);
    int v[]={2,1,1,1,1,1,1,1,1}; 
    given(v,9);
}




