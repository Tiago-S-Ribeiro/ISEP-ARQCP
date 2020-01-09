#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h>

#include <string.h>
  
 #include "asm.h"

 int call_func(short (*f)()); 
 
 extern short s; 
 extern short wall1; 
 extern short wall2; 
 
} 

//START: testGroup
TEST_GROUP(swapBytes)
{
    short expected;
    void setup()
    {
      wall1=0xaa55;  
      wall2=0xaa55;  
       
    }
    void teardown()
    {
    }
    void expect(short res)
    {
       expected = res;

	}
    void given(short x )
    { 
        short r;
        s=x;  
        r=call_func(swapBytes); 
        
	LONGS_EQUAL(x & 0xffff ,s & 0xffff ); 
	LONGS_EQUAL(expected ,r  ); 
	LONGS_EQUAL(0xaa55  ,wall1 & 0xffff ); 
	LONGS_EQUAL(0xaa55  ,wall2 & 0xffff ); 

    }
};
//END: testGroup


TEST(swapBytes, Zero)
{
    expect(0);
    given(0);
}


TEST(swapBytes, OneA)
{
    expect(256);
    given(1);
}

TEST(swapBytes, OneB)
{
    expect(1);
    given(256);
}


TEST(swapBytes, Minus1)
{
    expect(-1);
    given(-1);
}


TEST(swapBytes, Big)
{
    expect(0xff00);
    given(0xff);
}

TEST(swapBytes, Big2)
{
    expect(0xff);
    given(0xff00);
}
//END: RefactoredTests


