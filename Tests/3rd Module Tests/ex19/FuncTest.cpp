#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h> 
#include <string.h> 
#include "asm.h"   	
char  * ptrgrades;  
int  * ptrfreq;  
int num;  

void call_func(void (*f)()); 

}

//START: testGroup
TEST_GROUP(frequencies)
{
    char test_vec[100]; 
    int out_vec[100]; 
	
    int *expected;

    void setup()
    {
        memset(test_vec, 0xaa, sizeof test_vec);
        memset(out_vec, 0xaa, sizeof out_vec);
        expected = NULL; 
	ptrgrades=test_vec;  
 	ptrfreq=out_vec; 	
    }
    void teardown()
    {
    }
    void expect(int * exp)
    {
        expected = exp;
    }
    void given(char * vec, int num_elem)
    { 
	memcpy(test_vec,vec,num_elem*sizeof(char)); 
	num=num_elem; 
	call_func(frequencies); 
	MEMCMP_EQUAL(expected,out_vec,21*sizeof(int)) ; 
        BYTES_EQUAL(0xaa, test_vec[num_elem]& 0xff);
        BYTES_EQUAL(0xaa, out_vec[21]& 0xff);
    }
};
//END: testGroup

TEST(frequencies, NullVector)
{
          // 0 1 2 3 4 5  6 7 8 9 0   1 2 3 4 5  6 7 8 9 0			
    int e[]={0,0,0,0,0,0, 0,0,0,0,0,  0,0,0,0,0, 0,0,0,0,0}; 
    expect(e); 
    char v[]={0}; 
    given(v,0);
}

TEST(frequencies, One)
{
          // 0 1 2 3 4 5  6 7 8 9 0   1 2 3 4 5  6 7 8 9 0			
    int e[]={0,1,0,0,0,0, 0,0,0,0,0,  0,0,0,0,0, 0,0,0,0,0}; 
    expect(e);
    char v[]={1}; 
    given(v,1);
}


TEST(frequencies,Zero)
{
          // 0 1 2 3 4 5  6 7 8 9 0   1 2 3 4 5  6 7 8 9 0			
    int e[]={1,1,1,0,0,0, 0,0,0,0,0,  0,0,0,0,0, 0,0,0,0,0}; 
    expect(e);
    char v[]={2,0,1}; 
    given(v,3);
}


TEST(frequencies,MinusThree)
{
          // 0 1 2 3 4 5  6 7 8 9 0   1 2 3 4 5  6 7 8 9 0			
    int e[]={0,0,0,1,0,0, 0,0,0,0,1,  0,0,0,0,0, 0,0,0,0,1}; 
    expect(e);
    char v[]={10,20,3}; 
    given(v,3);
}

TEST(frequencies,Ten)
{
          // 0 1 2 3 4 5  6 7 8 9 0   1 2 3 4 5  6 7 8 9 0			
    int e[]={0,0,0,0,0,0, 0,0,0,0,8,  0,0,0,0,0, 0,0,0,0,1}; 
    expect(e);
    char v[]={20,10,10,10,10,10,10,10,10}; 
    given(v,9);
}




