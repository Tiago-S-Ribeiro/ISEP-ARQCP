#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h>

#include <string.h>
  
 #include "asm.h"

 int  call_func(int   (*f)()); 

 extern int code; 
 extern int currentSalary; 
 extern int wall1; 
 extern int wall2; 
 extern int wall3; 
 
} 

//START: testGroup
TEST_GROUP(new_salary)
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
    void given(int x, int y  )
    { 
        int  r; 
        code=x; 
        currentSalary=y; 
        r=call_func(new_salary); 
        
	LONGS_EQUAL(x,code); 
	LONGS_EQUAL(y,currentSalary); 
	LONGS_EQUAL(expected,r); 
	LONGS_EQUAL(0x12345678,wall1); 
	LONGS_EQUAL(0x12345678,wall2); 
	LONGS_EQUAL(0x12345678,wall3); 

    }
};
//END: testGroup


TEST(new_salary, Zero)
{
    expect(100);
    given(0,0);
}


TEST(new_salary, Case1) 
{
    expect(300);
    given(10,0);
}

TEST(new_salary, Two) 
{
    expect(250);
    given(11,0);
} 

TEST(new_salary, Three)
{
    expect(150);
    given(12,0);
}


TEST(new_salary, Big1)
{
    expect(1100);
    given(5,1000);
}

TEST(new_salary, Big2)
{
    expect(1150);
    given(12,1000);
}

TEST(new_salary, Big3)
{
    expect(1250);
    given(11,1000);
}

TEST(new_salary, Big4)
{
    expect(1300);
    given(10,1000);
}



//END: RefactoredTests


