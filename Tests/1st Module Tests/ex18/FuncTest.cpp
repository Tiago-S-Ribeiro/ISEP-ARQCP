#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h> 
#include <string.h> 
#include "asm.h"   	
}

//START: testGroup
TEST_GROUP(compress_shorts)
{
    int iv[50];
    short sv[100];

    void setup()
    {
        memset(iv, 0xaa, sizeof iv);
        memset(sv, 0xaa, sizeof sv);
    }
    void teardown()
    {
    }
    void expect()
    {
    }
    void given(short * v1, int num )
    { 
	memcpy(sv,v1,num*sizeof(short)); 
	compress_shorts(sv,num,iv); 
	MEMCMP_EQUAL(v1,sv,num*sizeof(short)) ; 
	MEMCMP_EQUAL(v1,iv,num*sizeof(short)) ; 
        BYTES_EQUAL(0xaa, sv[num]& 0xff);
        BYTES_EQUAL(0xaa, iv[num/2]& 0xff);

    }
};
//END: testGroup

TEST(compress_shorts, NullVector)
{
    short v1[]={0}; 
    expect(); 
    given(v1,0);
}

TEST(compress_shorts, One)
{
    short v1[]={1,2}; 
    expect(); 
    given(v1,2);
}




TEST(compress_shorts, Three)
{
    short v1[]={0,1,2,4,5,6}; 
    expect(); 
    given(v1,6);
} 




TEST(compress_shorts, Four)
{
   short v1[]={1,1,1,1,-1,-1,-1,-1}; 
    expect(); 
    given(v1,8);
} 
