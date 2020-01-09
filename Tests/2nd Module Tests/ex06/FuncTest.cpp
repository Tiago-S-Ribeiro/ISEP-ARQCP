#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h>

#include <string.h>
  
 #include "asm.h"

 short call_func(short (*f)()); 
 
 extern char byte1; 
 extern char byte2; 
 extern char wall1; 
 extern char wall2; 
 extern char wall3; 
 
} 

//START: testGroup
TEST_GROUP(concatBytes)
{
    short expected;
    void setup()
    {
      wall1=0x78;  
      wall2=0x78;  
      wall3=0x78;  
       
    }
    void teardown()
    {
    }
    void expect(short res)
    {
       expected = res;

	}
    void given(char x, char y )
    { 
        short r; 
        byte1=x; 
        byte2=y; 
        r=call_func(concatBytes); 
        
	BYTES_EQUAL(x,byte1); 
	BYTES_EQUAL(y,byte2); 
	LONGS_EQUAL(expected,r); 
	BYTES_EQUAL(0x78,wall1); 
	BYTES_EQUAL(0x78,wall2); 
	BYTES_EQUAL(0x78,wall3); 

    }
};
//END: testGroup


TEST(concatBytes, Zero)
{
    expect(0);
    given(0,0);
}


TEST(concatBytes, OneA)
{
    expect(256);
    given(0,1);
}

TEST(concatBytes, OneB)
{
    expect(1);
    given(1,0);
}


TEST(concatBytes, Minus1)
{
    expect(-1);
    given(-1,-1);
}


TEST(concatBytes, Big)
{
    expect(0x3232);
    given(50,50);
}

TEST(concatBytes, Big2)
{
    expect(0x3200);
    given(0,50);
}
//END: RefactoredTests


