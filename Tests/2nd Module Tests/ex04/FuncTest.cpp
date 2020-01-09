#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h>

#include <string.h>
  
 #include "asm.h"

 int call_func(int (*f)()); 
 
 extern int op1; 
 extern int op2; 
 extern int wall1; 
 extern int wall2; 
 extern int wall3; 
 
} 

//START: testGroup
TEST_GROUP(sum_v3)
{
    int expected;
    void setup()
    {
      wall1=0x12345678;  
      wall2=0x12345678;  
      wall3=0x12345678;  
       
    }
    void teardown()
    {
    }
    void expect(int res)
    {
       expected = res;

	}
    void given(int x, int y,int z, int w )
    { 
        int r; 
        op1=x; 
        op2=y; 
        op3=z; 
        op4=w; 
        
        r=call_func(sum_v3); 
        
	LONGS_EQUAL(x,op1); 
	LONGS_EQUAL(y,op2); 
	LONGS_EQUAL(z,op3); 
	LONGS_EQUAL(w,op4); 
	LONGS_EQUAL(expected,r); 
	LONGS_EQUAL(0x12345678,wall1); 
	LONGS_EQUAL(0x12345678,wall2); 
	LONGS_EQUAL(0x12345678,wall3); 

    }
};
//END: testGroup


TEST(sum_v3, Zero)
{
    expect(0);
    given(0,0,0,0);
}


TEST(sum_v3, OneA)
{
    expect(1);
    given(0,1,1,1);
}

TEST(sum_v3, OneB)
{
    expect(-1);
    given(0,1,0,0);
}


TEST(sum_v3, Minus3)
{
    expect(-3);
    given(1,-1,-6,1);
}


TEST(sum_v3, Big)
{
    expect(5000);
    given(5000,10000,6000,4000);
}

TEST(sum_v3, Big2)
{
    expect(50000);
    given(50000,100000,50000,50000);
}
//END: RefactoredTests


