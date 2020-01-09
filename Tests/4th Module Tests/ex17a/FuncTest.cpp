#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h> 
#include <string.h> 
#include "asm.h"   	 

void call_func(void (*f)(char, int*, int* ), int p_param,char, int * , int *   ); 

}

//START: testGroup
TEST_GROUP(add_byte)
{
    int test_vec[100]; 
    int out_vec[100]; 
	
    int *expected;

    void setup()
    {
        memset(test_vec, 0xaa, sizeof test_vec);
        memset(out_vec, 0xaa, sizeof out_vec);
        expected = NULL; 
    }
    void teardown()
    {
    }
    void expect(int * exp)
    {
        expected = exp;
    }
    void given(int x, int * vec, int num_elem)
    { 
	memcpy(test_vec,vec,num_elem*sizeof(int)); 
	call_func(add_byte,3,x, vec ,out_vec); 
	MEMCMP_EQUAL(expected,out_vec,num_elem*sizeof(int)) ; 
        BYTES_EQUAL(0xaa, test_vec[num_elem]& 0xff);
        BYTES_EQUAL(0xaa, out_vec[num_elem==0 ? 1 : num_elem]& 0xff);
    }
};
//END: testGroup

TEST(add_byte, NullVector)
{
          // 			
    int e[]={}; 
    expect(e); 
    int v[]={0}; 
    given(0,v,0);
}

TEST(add_byte, One)
{
    unsigned int e[]={6,0xffffff04,0x04,0xfffff004,0xfffff804,5,9}; 
    expect((int*)e);
    unsigned int v[]={6,0xffffffff,0xff,0xfffff0ff,0xfffff8ff,0,4}; 
    given(5,(int*)v,7);
}





