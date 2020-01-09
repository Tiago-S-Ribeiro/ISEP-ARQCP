#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h>

#include <string.h>
  
 #include "asm.h"

 int  call_func(int   (*f)()); 

 extern int num; 
 extern int wall1; 
 extern int wall2; 
 
} 

//START: testGroup
TEST_GROUP(steps)
{
    int  expected;
    void setup()
    {
      wall1=0x12345678;  
      wall2=0x12345678;  
       
    }
    void teardown()
    {
    }
    void expect(int res)
    {
       expected = res;

	}
    void given(int x )
    { 
        int  r; 
        num=x; 
        r=call_func(steps); 
        
	LONGS_EQUAL(x,num); 
	LONGS_EQUAL(expected,r); 
	LONGS_EQUAL(0x12345678,wall1); 
	LONGS_EQUAL(0x12345678,wall2); 

    }
};
//END: testGroup


TEST(steps, Zero)
{
    expect(13);
    given(0);
}


TEST(steps, Case1) 
{
    expect(13);
    given(1);
}

TEST(steps, Two) 
{
    expect(13);
    given(2);
} 

TEST(steps, Minus1)
{
    expect(13);
    given(-1);
}


TEST(steps, Minus10)
{
    expect(13);
    given(-1);
}

TEST(steps, CaseBig)
{
    expect(13);
    given(0x7ffffff);
}


//END: RefactoredTests


