#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h> 
#include <string.h> 
#include "asm.h"    

void call_func(void (*f)(int * ), int p_param, int * ); 

}

//START: testGroup
TEST_GROUP(changes)
{
    int  expected;  

    void setup()
    {
        expected =0;  
    }
    void teardown()
    {
    }
    void expect(int num )
    {
        expected = num; 
    }
    void given(int x )
    { 
        int wall1=0x12345678; 
	int result=x; 
        int wall2=0x87654321; 
	call_func(changes,1,&result); 
        LONGS_EQUAL(expected, result);
        LONGS_EQUAL(wall1,0x12345678); 
        LONGS_EQUAL(wall2,0x87654321); 
    }
};
//END: testGroup

TEST(changes, Zero)
{
    expect(0);	  
    given(0);	
}

TEST(changes, One)
{
    expect(0xff0fffff);	  
    given(-1);	
}
TEST(changes, Two)
{
    expect(0xff);	  
    given(0xff);	
}
TEST(changes, Three)
{
    expect(0xff0fffff);	  
    given(0xff0fffff);	
}


TEST(changes, Four)
{
    expect(0xff7ff0ff);	  
    given(0xff8ff0ff);	
}



TEST(changes, Five)
{
    expect(0xff7fffff);	  
    given(0xff7fffff);	
} 


TEST(changes, Six)
{
    expect(0x00700000);	  
    given(0x00700000);	
} 



TEST(changes, Seven)
{
    expect(0x00700000);	  
    given(0x00800000);	
} 


