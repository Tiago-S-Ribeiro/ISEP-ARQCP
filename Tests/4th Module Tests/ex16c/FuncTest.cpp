#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h> 
#include <string.h> 
#include "asm.h"   	
int  * ptrvec;  
void call_func(void (*f)(int * , int ), int p_param, int *, int ); 

}

//START: testGroup
TEST_GROUP(changes_vec)
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
	call_func(changes_vec,2,ptrvec,num_elem); 
	MEMCMP_EQUAL(expected,test_vec,num_elem*sizeof(int)) ; 
        BYTES_EQUAL(0xaa, test_vec[num_elem]& 0xff);
    }
};
//END: testGroup

TEST(changes_vec, NullVector)
{
    int e[]={0}; 
    expect(e); 
    int v[]={0}; 
    given(v,0);
}

TEST(changes_vec, One)
{
    int e[]={1}; 
    expect(e);
    int v[]={1}; 
    given(v,1);
}


TEST(changes_vec,Three)
{
    int e[]={2,1,0}; 
    expect(e);
    int v[]={2,1,0}; 
    given(v,3);
}


TEST(changes_vec,Full)
{
    unsigned int e[]={0,0xff0fffff,0xff,0xff0fffff,0xff7fffff,0xff7fffff,0x700000,0x700000}; 
    expect((int*)e);
    unsigned int v[]={0,0xffffffff,0xff,0xff0fffff,0xff8fffff,0xff7fffff,0x700000,0x800000}; 
    given((int*)v,8);
}





