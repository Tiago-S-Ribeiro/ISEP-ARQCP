#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h>

#include <string.h>
  
 #include "asm.h"

 long long  call_func(long long  (*f)()); 
 
 extern int C; 
 extern int D;  
 extern char A; 
 extern short B ; 
 extern int wall1; 
 extern int wall2; 
 extern short wall3; 
 extern char wall4; 
 extern short wall5; 
 
} 

//START: testGroup
TEST_GROUP(sum_and_subtract)
{
    long long  expected;
    void setup()
    {
      wall1=0x12345678;  
      wall2=0x12345678;  
      wall3=0x1234;  
      wall4=0x34;  
      wall5=0x1234;  
       
    }
    void teardown()
    {
    }
    void expect(long long res)
    {
       expected = res;

	}
    void given(int x, int y , char  w , short z)
    { 
        long long  r; 
        C=x; 
        D=y; 
 	A=w; 
        B=z; 
        r=call_func(sum_and_subtract); 
        
	LONGS_EQUAL(x,C); 
	LONGS_EQUAL(y,D); 
        BYTES_EQUAL(w,A); 
        LONGS_EQUAL(z,B); 
	MEMCMP_EQUAL(&expected,&r,8); 
	LONGS_EQUAL(0x12345678,wall1); 
	LONGS_EQUAL(0x12345678,wall2); 
	LONGS_EQUAL(0x1234,wall3); 
	BYTES_EQUAL(0x34,wall4); 
	LONGS_EQUAL(0x1234,wall5); 

    }
};
//END: testGroup


TEST(sum_and_subtract, Zero)
{
    expect(0);
    given(0,0,0,0);
}


TEST(sum_and_subtract, OneA)
{
    expect(1);
    given(1,0,0,0);
}

TEST(sum_and_subtract, OneB)
{
    expect(1);
    given(0,0,0,1);
}


TEST(sum_and_subtract, Minus1)
{
    expect(-1);
    given(0,1,0,0);
}

TEST(sum_and_subtract, Minus1b)
{
    expect(-1);
    given(0,0,0,-1);
}


TEST(sum_and_subtract, Big)
{
    expect(10000);
    given(5000,-5000,-1,1);
}

TEST(sum_and_subtract, Big2)
{
    expect(100000);
    given(50000,-50000,20,-20);
}
//END: RefactoredTests


