#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h>

#include <string.h>
  
#include "asm.h"

 char  call_func(char   (*f)()); 

 extern int num; 
 extern int wall1; 
 extern int wall2; 
 
} 

//START: testGroup
TEST_GROUP(check_num)
{
    char  expected;
    void setup()
    {
      wall1=0x12345678;  
      wall2=0x12345678;  
       
    }
    void teardown()
    {
    }
    void expect(char res)
    {
       expected = res;

	}
    void given(int x )
    { 
        char  r; 
        num=x; 
        r=call_func(check_num); 
        
	LONGS_EQUAL(x,num); 
	BYTES_EQUAL(expected,r); 
	LONGS_EQUAL(0x12345678,wall1); 
	LONGS_EQUAL(0x12345678,wall2); 

    }
};
//END: testGroup


TEST(check_num, Zero)
{
    expect(3);
    given(0);
}


TEST(check_num, Case1) 
{
    expect(4);
    given(1);
}

TEST(check_num, Two) 
{
    expect(3);
    given(2);
} 

TEST(check_num, Minus1)
{
    expect(2);
    given(-1);
}


TEST(check_num, Minus10)
{
    expect(1);
    given(-10);
}

TEST(check_num, CaseBig)
{
    expect(2);
    given(0xffffffff);
}
TEST(check_num, CaseBig2)
{
    expect(1);
    given(0xfffffffe);
}


//END: RefactoredTests


