#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h> 
#include <string.h> 
#include "asm.h"
}

//START: testGroup
TEST_GROUP(copy_vec)
{
    int in_vec[100];
    int out_vec[100];
    int *expected;
    void setup()
    {
        memset(in_vec, 0xaa, sizeof in_vec);
        memset(out_vec, 0xaa, sizeof out_vec);
        expected = NULL; 
    }
    void teardown()
    {
    }
    void expect(int * exp)
    {
        expected = out_vec;
    }
    void given(int * vec, int num_elem)
    {
    	
    memcpy(in_vec,vec,num_elem*sizeof(int));  // vetor entrada 
	copy_vec(in_vec,out_vec,num_elem);
	MEMCMP_EQUAL(expected,vec,num_elem*sizeof(int)) ; 
	MEMCMP_EQUAL(in_vec,vec,num_elem*sizeof(int)) ; 
	BYTES_EQUAL(0xaa, in_vec[num_elem]& 0xff);
	BYTES_EQUAL(0xaa, in_vec[num_elem]& 0xff);
    }
};
//END: testGroup

TEST(copy_vec, NullVector)
{
    int e[]={0}; 
    expect(e); 
    int v[]={0}; 
    given(v,0);
}

TEST(copy_vec, One)
{
    int e[]={1}; 
    expect(e);
    int v[]={1}; 
    given(v,1);
}


TEST(copy_vec,Zero)
{
    int e[]={-1,0,2}; 
    expect(e);
    int v[]={-1,0,2}; 
    given(v,3);
}


TEST(copy_vec,MinusThree)
{
    int e[]={-1,-1,-1}; 
    expect(e);
    int v[]={-1,-1,-1}; 
    given(v,3);
}

TEST(copy_vec,Ten)
{
    int e[]={0,1,2,3,4,5,6,7,-2}; 
    expect(e);
    int v[]={0,1,2,3,4,5,6,7,-2}; 
    given(v,9);
}




