#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h>

#include <string.h>
  
 #include "asm.h"

 short call_func(short (*f)()); 
 
 extern short s1; 
 extern short s2; 
 extern short wall1; 
 extern short wall2; 
 extern short wall3; 
 
} 

//START: testGroup
TEST_GROUP(crossSumBytes)
{
    int expected;
    void setup()
    {
      wall1=0x7878;  
      wall2=0x7878;  
      wall3=0x7878;  
       
    }
    void teardown()
    {
    }
    void expect(short res)
    {
       expected = (int)res; 

	}
    void given(short x, short y )
    { 
        short r; 
        s1=x; 
        s2=y; 
        r=call_func(crossSumBytes); 
        
	LONGS_EQUAL(x,s1 &0xffff); 
	LONGS_EQUAL(y,s2 &0xffff); 
	LONGS_EQUAL(expected ,r ); 
	LONGS_EQUAL(0x7878,wall1 &0xffff); 
	LONGS_EQUAL(0x7878,wall2 &0xffff); 
	LONGS_EQUAL(0x7878,wall3 &0xffff); 

    }
};
//END: testGroup


TEST(crossSumBytes, Zero)
{
    expect(0);
    given(0,0);
}


TEST(crossSumBytes, OneA)
{
    expect(256);
    given(0,1);
}

TEST(crossSumBytes, OneB)
{
    expect(257);
    given(1,1);
}


TEST(crossSumBytes, Minus1)
{
    expect(-1);
    given(0xff,0xff);
}


TEST(crossSumBytes, Big)
{
    expect(0x4466);
    given(0x2233,0x3322);
}

TEST(crossSumBytes, Big2)
{
    expect(0x88aa);
    given(0x4455,0x5544);
}
//END: RefactoredTests


