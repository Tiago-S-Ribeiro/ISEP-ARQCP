#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h>

#include <string.h>
  
 #include "asm.h"

 char  call_func(char   (*f)()); 

 extern int A; 
 extern int B;   
 extern int wall1; 
 extern int wall2; 
 extern int wall3; 
 
} 

//START: testGroup
TEST_GROUP(isMultiple)
{
    char  expected;
    void setup()
    {
      wall1=0x12345678;  
      wall2=0x12345678;  
      wall3=0x12345678;  
       
    }
    void teardown()
    {
    }
    void expect(char res)
    {
       expected = res;

	}
    void given(int x, int y )
    { 
        char  r; 
        A=x; 
        B=y; 
        r=call_func(isMultiple); 
        
	LONGS_EQUAL(x,A); 
	LONGS_EQUAL(y,B); 
	BYTES_EQUAL(expected,r); 
	LONGS_EQUAL(0x12345678,wall1); 
	LONGS_EQUAL(0x12345678,wall2); 
	LONGS_EQUAL(0x12345678,wall3); 

    }
};
//END: testGroup


TEST(isMultiple, Zero)
{
    expect(0);
    given(0,0);
}


TEST(isMultiple, OneA)
{
    expect(0);
    given(1,-1);
}

TEST(isMultiple, OneB)
{
    expect(1);
    given(100,5);
} 

TEST(isMultiple, OneC)
{
    expect(1);
    given(0x8000000,0x8000);
}


TEST(isMultiple, Minus1)
{
    expect(0);
    given(2,78);
}

TEST(isMultiple, Minus1b)
{
    expect(0);
    given(100000,1000000);
}


TEST(isMultiple, Big)
{
    expect(1);
    given(5000,5000);
}

TEST(isMultiple, Big2)
{
    expect(1);
    given(5000000,5000);
}
//END: RefactoredTests


