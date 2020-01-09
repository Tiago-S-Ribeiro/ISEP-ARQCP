#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h> 
#include <string.h> 
#include "asm.h"    

int call_func(int (*f)(int, int), int p_param, int ,int ); 

void print_result(char op, int o1, int o2, int res)
   {
     printf("%d %c %d = %d\n", o1, op, o2, res);
   }


}

//START: testGroup
TEST_GROUP(calculate)
{
    int  expected;
    void setup()
    {
        expected = 0; 
    }
    void teardown()
    {
    }
    void expect(int num )
    {
        expected = num;
    }
    void given(int x ,int y )
    { 
	int result; 
	result=call_func(calculate,2,x,y); 
        LONGS_EQUAL(expected, result);
    }
};
//END: testGroup

TEST(calculate, Zero)
{
    expect(0);
    given(0,0);
}

TEST(calculate, One)
{
    expect(1);
    given(1,-1);
}

TEST(calculate, OneB)
{
    expect(1);
    given(-1,1);
}


TEST(calculate, ThreeFive)
{
    expect(-7);
    given(3,5);
}


TEST(calculate, FiveThree)
{
    expect(-7);
    given(5,3);
}


TEST(calculate, ThreeThree)
{
    expect(-3);
    given(3,3);
}

