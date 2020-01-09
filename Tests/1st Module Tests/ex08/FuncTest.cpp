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
TEST_GROUP(array_sort2)
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
	array_sort2(test_vec,num_elem); 
	MEMCMP_EQUAL(expected,test_vec,num_elem*sizeof(int)) ; 
        BYTES_EQUAL(0xaa, test_vec[num_elem]& 0xff);
    }
};
//END: testGroup

TEST(array_sort2, NullVector)
{
    int e[]={0}; 
    expect(e); 
    int v[]={0}; 
    given(v,0);
}

TEST(array_sort2, One)
{
    int e[]={1}; 
    expect(e);
    int v[]={1}; 
    given(v,1);
}


TEST(array_sort2,Zero)
{
    int e[]={0,1,2}; 
    expect(e);
    int v[]={0,1,2}; 
    given(v,3);
}


TEST(array_sort2,MinusThree)
{
    int e[]={-3,-2,-1}; 
    expect(e);
    int v[]={-1,-2,-3}; 
    given(v,3);
}

TEST(array_sort2,Ten)
{
    int e[]={1,1,1,1,1,1,1,1,2}; 
    expect(e);
    int v[]={2,1,1,1,1,1,1,1,1}; 
    given(v,9);
}




