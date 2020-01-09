#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h>

#include <string.h>
  
 #include "asm.h"

 int  call_func(int   (*f)()); 

 extern int A; 
 extern int B; 
 extern int C; 
 extern int D; 
 extern int wall1; 
 extern int wall2; 
 extern int wall3; 
 extern int wall4; 
 extern int wall5; 
 
} 

//START: testGroup
TEST_GROUP(compute)
{
    int  expected;
    void setup()
    {
      wall1=0x12345678;  
      wall2=0x12345678;  
      wall3=0x12345678;  
      wall4=0x12345678;  
      wall5=0x12345678;  
       
    }
    void teardown()
    {
    }
    void expect(int res)
    {
       expected = res;

	}
    void given(int x, int y ,int w , int z )
    { 
        int  r; 
        A=x; 
        B=y; 
        C=w; 
        D=z; 
        r=call_func(compute); 
        
	LONGS_EQUAL(x,A); 
	LONGS_EQUAL(y,B); 
	LONGS_EQUAL(w,C); 
	LONGS_EQUAL(z,D); 
	LONGS_EQUAL(expected,r); 
	LONGS_EQUAL(0x12345678,wall1); 
	LONGS_EQUAL(0x12345678,wall2); 
	LONGS_EQUAL(0x12345678,wall3); 
	LONGS_EQUAL(0x12345678,wall4); 
	LONGS_EQUAL(0x12345678,wall5); 

    }
};
//END: testGroup


TEST(compute, Zero)
{
    expect(0);
    given(0,0,0,0);
}


TEST(compute, Zero1) 
{
    expect(0);
    given(0,0,0,2);
}

TEST(compute, Two) 
{
    expect(2);
    given(2,2,0,2);
} 

TEST(compute, Case1)
{
    expect(6399996);
    given(8000,-8000,40,-10);
}


TEST(compute, Case2)
{
    expect(-214171);
    given(3000,-5000,8000,70);
}

TEST(compute, Case3)
{
    expect(100100);
    given(1000,1000,1000,10);
}


TEST(compute, Case4)
{
    expect(-5583);
    given(50,5,50005,-9);
}

TEST(compute, Case5)
{
    expect(-357142);
    given(50000,-50,6,7);
}
//END: RefactoredTests


