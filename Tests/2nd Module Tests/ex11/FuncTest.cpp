#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h>

#include <string.h>
  
 #include "asm.h"

 char  call_func(char   (*f)()); 

 extern int op1; 
 extern int op2;  
 extern int wall1; 
 extern int wall2; 
 extern int wall3; 
 
} 

//START: testGroup
TEST_GROUP(test_flags)
{
    long long  expected;
    void setup()
    {
      wall1=0x12345678;  
      wall2=0x12345678;  
      wall3=0x12345678;  
       
    }
    void teardown()
    {
    }
    void expect(long long res)
    {
       expected = res;

	}
    void given(int x, int y )
    { 
        char  r; 
        op1=x; 
        op2=y; 
        r=call_func(test_flags); 
        
	LONGS_EQUAL(x,op1); 
	LONGS_EQUAL(y,op2); 
	BYTES_EQUAL(expected,r); 
	LONGS_EQUAL(0x12345678,wall1); 
	LONGS_EQUAL(0x12345678,wall2); 
	LONGS_EQUAL(0x12345678,wall3); 

    }
};
//END: testGroup


TEST(test_flags, Zero)
{
    expect(0);
    given(0,0);
}


TEST(test_flags, OneA)
{
    expect(1);
    given(1,-1);
}

TEST(test_flags, OneB)
{
    expect(1);
    given(1,0x7fffffff);
} 

TEST(test_flags, OneC)
{
    expect(1);
    given(0x80000000,0x80000000);
}


TEST(test_flags, Minus1)
{
    expect(0);
    given(2,78);
}

TEST(test_flags, Minus1b)
{
    expect(0);
    given(100000,1000000);
}


TEST(test_flags, Big)
{
    expect(0);
    given(5000,5000);
}

TEST(test_flags, Big2)
{
    expect(0);
    given(500000,500000);
}
//END: RefactoredTests


