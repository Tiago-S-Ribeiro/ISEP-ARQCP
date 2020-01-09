#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h> 
#include <string.h> 
#include "asm.h"   	
short  * ptrvec;  
int num;  

 int call_func(int (*f)()); 
}

//START: testGroup
TEST_GROUP(vec_zero)
{
    short test_vec[100];
    short  *expected; 
    int ret_value; 
    void setup()
    {
        memset(test_vec, 0xaa, sizeof test_vec);
        expected = NULL; 
        ret_value=0; 
	ptrvec=test_vec; 
    }
    void teardown()
    {
    }
    void expect(short * exp,int ret)
   { 
	ret_value=ret; 
        expected = exp;
    }
    void given(short * vec, int num_elem)
    { 
	int result; 
	memcpy(test_vec,vec,num_elem*sizeof(short)); 
	num=num_elem; 
	result=call_func(vec_zero); 
	MEMCMP_EQUAL(expected,test_vec,num_elem*sizeof(short)) ; 
        LONGS_EQUAL(ret_value,result); 	
        BYTES_EQUAL(0xaa, test_vec[num_elem]& 0xff);
    }
};
//END: testGroup

TEST(vec_zero, NullVector)
{
    short e[]={(short)0xaaaa}; 
    expect(e,0); 
    short v[]={0}; 
    given(v,0);
}

TEST(vec_zero, One)
{
    short e[]={0}; 
    expect(e,1);
    short v[]={1000}; 
    given(v,1);
}


TEST(vec_zero,Zero)
{
    short e[]={1,0,-1}; 
    expect(e,0);
    short v[]={1,0,-1}; 
    given(v,3);
}


TEST(vec_zero,MinusThree)
{
    short e[]={-1,-1,-1}; 
    expect(e,0);
    short v[]={-1,-1,-1}; 
    given(v,3);
}

TEST(vec_zero,Nine)
{
    short e[]={0,0,0,0,0,0,0,0,0}; 
    expect(e,9);
    short v[]={100,100,100,100,1000,1000,1000,1000,2000}; 
    given(v,9);
}




