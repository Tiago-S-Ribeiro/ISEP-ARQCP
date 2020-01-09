#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h>

#include <string.h>
  
 #include "asm.h"

 long long  call_func(long long  (*f)()); 
 
 extern int op1; 
 extern int op2;  
 extern int wall1; 
 extern int wall2; 
 extern int wall3; 
 
} 

//START: testGroup
TEST_GROUP(sum2ints)
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
        long long  r; 
        op1=x; 
        op2=y; 
        r=call_func(sum2ints); 
        
	LONGS_EQUAL(x,op1); 
	LONGS_EQUAL(y,op2); 
	MEMCMP_EQUAL(&expected,&r,8); 
	LONGS_EQUAL(0x12345678,wall1); 
	LONGS_EQUAL(0x12345678,wall2); 
	LONGS_EQUAL(0x12345678,wall3); 

    }
};
//END: testGroup


TEST(sum2ints, Zero)
{
    expect(0);
    given(0,0);
}


TEST(sum2ints, OneA)
{
    expect(1);
    given(1,0);
}

TEST(sum2ints, OneB)
{
    expect(1);
    given(0,1);
}


TEST(sum2ints, Minus1)
{
    expect(-1);
    given(0,-1);
}

TEST(sum2ints, Minus1b)
{
    expect(-1);
    given(-1,0);
}


TEST(sum2ints, Big)
{
    expect(10000);
    given(5000,5000);
}

TEST(sum2ints, Big2)
{
    expect(100000);
    given(50000,50000);
}
//END: RefactoredTests


