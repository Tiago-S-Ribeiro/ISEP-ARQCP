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
TEST_GROUP(swap)
{
    int tv1[100];
    int tv2[100];

    void setup()
    {
        memset(tv1, 0xaa, sizeof tv1);
        memset(tv2, 0xaa, sizeof tv2);
    }
    void teardown()
    {
    }
    void expect()
    {
    }
    void given(int * v1, int * v2,  int num_elem)
    { 
	memcpy(tv1,v1,num_elem*sizeof(int)); 
	memcpy(tv2,v2,num_elem*sizeof(int)); 
	swap(tv1,tv2,num_elem); 
	MEMCMP_EQUAL(v1,tv2,num_elem*sizeof(int)) ; 
        BYTES_EQUAL(0xaa, tv2[num_elem]& 0xff);

	MEMCMP_EQUAL(v2,tv1,num_elem*sizeof(int)) ; 
        BYTES_EQUAL(0xaa, tv1[num_elem]& 0xff);
    }
};
//END: testGroup

TEST(swap, NullVector)
{
    int v1[]={0}; 
    int v2[]={0}; 
    expect(); 
    given(v1,v2,0);
}

TEST(swap, One)
{
    int v1[]={1}; 
    int v2[]={2}; 
    expect(); 
    given(v1,v2,1);
}




TEST(swap, Three)
{
    int v1[]={0,1,2}; 
    int v2[]={2,1,0}; 
    expect(); 
    given(v1,v2,3);
} 




TEST(swap, Four)
{
    int v1[]={1,1,1,1}; 
    int v2[]={-1,-1,-1,-1}; 
    expect(); 
    given(v1,v2,4);
} 
