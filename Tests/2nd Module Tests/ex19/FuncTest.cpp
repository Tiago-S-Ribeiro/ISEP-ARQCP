#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h>

#include <string.h>
  
 #include "asm.h"

 int  call_func(int   (*f)()); 

 extern short desired; 
 extern short current; 
 extern short wall1; 
 extern short wall2; 
 extern short wall3; 
 
} 

//START: testGroup
TEST_GROUP(needed_time)
{
    int  expected;
    void setup()
    {
      wall1=0x5678;  
      wall2=0x5678;  
      wall3=0x5678;  
       
    }
    void teardown()
    {
    }
    void expect(int res)
    {
       expected = res;

	}
    void given(short x, short y  )
    { 
        int  r; 
        current=x; 
        desired=y; 
        r=call_func(needed_time); 
        
	LONGS_EQUAL(x,current); 
	LONGS_EQUAL(y,desired); 
	LONGS_EQUAL(expected,r); 
	LONGS_EQUAL(0x5678,wall1); 
	LONGS_EQUAL(0x5678,wall2); 
	LONGS_EQUAL(0x5678,wall3); 

    }
};
//END: testGroup


TEST(needed_time, Zero)
{
    expect(0);
    given(0,0);
}


TEST(needed_time, Case1) 
{
    expect(20*60);
    given(0,10);
}

TEST(needed_time, Two) 
{
    expect(2*60);
    given(2,3);
} 

TEST(needed_time, Minus1)
{
    expect(3*60);
    given(3,2);
}


TEST(needed_time, Minus10)
{
    expect(30*60);
    given(5,-5);
}

TEST(needed_time, PlusTenA)
{
    expect(20*60);
    given(-15,-5);
}


TEST(needed_time, Minus10A)
{
    expect(30*60);
    given(-5,-15);
}

TEST(needed_time, PlusTen)
{
    expect(20*60);
    given(-5,5);
}


//END: RefactoredTests


