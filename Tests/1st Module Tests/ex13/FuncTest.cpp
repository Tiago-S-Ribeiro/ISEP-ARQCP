#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h> 
#include <string.h> 
#include "asm.h"   	
}

//START: testGroup
TEST_GROUP(where_is)
{
    int test_vec[100];
    int *expected;
    int res_expect; 
    void setup()
    {
        memset(test_vec, 0xaa, sizeof test_vec);
        expected = NULL; 
    }
    void teardown()
    {
    }
    void expect(int num, int * exp)
    {
        expected = exp;
	res_expect= num; 
    }
    void given( char c, char  * str)
    {  
	int r; 
	r=where_is(str,c,test_vec); 
	MEMCMP_EQUAL(expected,test_vec,r*sizeof(int)) ; 
        BYTES_EQUAL(0xaa, test_vec[r]& 0xff);
    }
};
//END: testGroup

TEST(where_is, NullVector)
{
    int e[]={}; 
    expect(0,e); 
    given('c',(char*)"");
}

TEST(where_is, One)
{
    int e[]={1};
    expect(1,e);
    given('c',(char*)" c");
}


TEST(where_is,Three)
{
    int e[]={0,1,2}; 
    expect(3,e);
    given('c',(char*)"ccc");
}


TEST(where_is,ThreeInterval)
{
    int e[]={1,3,5}; 
    expect(3,e);
    given('c',(char*)" c c c");
}

TEST(where_is,Ten)
{

    int e[]={1,3,5}; 
    expect(3,e);
    given('x',(char*)"CxCxCxCCCCCCCC");
}




