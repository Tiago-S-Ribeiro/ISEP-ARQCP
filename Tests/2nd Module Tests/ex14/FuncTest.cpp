#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h>

#include <string.h>
  
 #include "asm.h"

 int  call_func(int   (*f)()); 

 extern int base; 
 extern int height;   
 extern int wall1; 
 extern int wall2; 
 extern int wall3; 
 
} 

//START: testGroup
TEST_GROUP(getArea)
{
    int  expected;
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
    void given(int x, int y )
    { 
        int  r; 
        base=x; 
        height=y; 
        r=call_func(getArea); 
        
	LONGS_EQUAL(x,base); 
	LONGS_EQUAL(y,height); 
	LONGS_EQUAL(expected,r); 
	LONGS_EQUAL(0x12345678,wall1); 
	LONGS_EQUAL(0x12345678,wall2); 
	LONGS_EQUAL(0x12345678,wall3); 

    }
};
//END: testGroup


TEST(getArea, Zero)
{
    expect(0);
    given(0,0);
}


TEST(getArea, Area1) 
{
    expect(1);
    given(1,2);
}

TEST(getArea, Area2) 
{
    expect(2);
    given(2,2);
} 

TEST(getArea, Area3)
{
    expect(320000);
    given(800,800);
}


TEST(getArea, Area4)
{
    expect(7);
    given(3,5);
}

TEST(getArea, Area5)
{
    expect(500000);
    given(1000,1000);
}


TEST(getArea, Area6)
{
    expect(12500000);
    given(5000,5000);
}

TEST(getArea, Area7)
{
    expect(1250000);
    given(50000,50);
}
//END: RefactoredTests


