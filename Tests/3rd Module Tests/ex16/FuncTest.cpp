#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h> 
#include <string.h> 
#include "asm.h"   	
char  * ptr1;  
char  * ptr2;  
int num;  
void call_func(void (*f)()); 

}

//START: testGroup
TEST_GROUP(swap)
{
    char test_vec1[100];
    char test_vec2[100];
    char *expected1;
    char *expected2;
    void setup()
    {
        memset(test_vec1, 0xaa, sizeof test_vec1);
        memset(test_vec2, 0xaa, sizeof test_vec2);
        expected1 = NULL; 
        expected2 = NULL; 
	ptr1=test_vec1; 
	ptr2=test_vec2; 
    }
    void teardown()
    {
    }
    void expect(char * exp1, char * exp2 )
    {
        expected1 = exp1;
        expected2 = exp2;
    }
    void given(char * vec1, char * vec2, int num_elem)
    { 
	memcpy(test_vec1,vec1,num_elem*sizeof(char)); 
	memcpy(test_vec2,vec2,num_elem*sizeof(char)); 
	num=num_elem; 
	call_func(swap); 
	MEMCMP_EQUAL(expected1,test_vec1,num_elem*sizeof(char)) ; 
	MEMCMP_EQUAL(expected2,test_vec2,num_elem*sizeof(char)) ; 
        BYTES_EQUAL(0xaa, test_vec1[num_elem]& 0xff);
        BYTES_EQUAL(0xaa, test_vec2[num_elem]& 0xff);
    }
};
//END: testGroup

TEST(swap, NullVector)
{
    char e[]={0}; 
    char v[]={0}; 
    expect(e,v); 
    given(v,e,0);
}

TEST(swap, One)
{
    char e[]={1}; 
    char v[]={-1}; 
    expect(e,v);
    given(v,e,1);
}


TEST(swap,Zero)
{
    char e[]={2,1,0}; 
    char v[]={2,0,1}; 
    expect(e,v);
    given(v,e,3);
}


TEST(swap,MinusThree)
{
    char e[]={-1,-2,-3}; 
    char v[]={-3,-3,-3}; 
    expect(e,v);
    given(v,e,3);
}

TEST(swap,Ten)
{
    char e[]={2,1,1,1,0,1,1,1,1}; 
    char v[]={1,1,0,1,1,1,1,1,122}; 
    expect(e,v);
    given(v,e,9);
}




