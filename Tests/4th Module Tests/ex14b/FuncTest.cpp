#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h> 
#include <string.h> 
#include "asm.h"    
int call_func(int (*f)(int , int , int  ), int p_param, int , int ,int ); 
}

//START: testGroup
TEST_GROUP(join_bits)
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
    void given(int x ,int y ,int z)
    { 
	int result; 
	result=call_func(join_bits,3,x,y,z); 
        LONGS_EQUAL(expected, result);
    }
};
//END: testGroup

TEST(join_bits, One)
{
    expect(0xfffffe00);
    given(0,-1,8);
}

TEST(join_bits, Two)
{
    expect(0x1ff);
    given(-1,0,8);
}

TEST(join_bits, Three)
{
    expect(0xfffffffe);
    given(0,-1,0);
}
TEST(join_bits,Four)
{
    expect(1);
    given(-1,0,0);
}

TEST(join_bits, Five)
{
    expect(0);
    given(0,-1,31);
}

TEST(join_bits, Six)
{
    expect(0xffffffff);
    given(-1,0,31);
}


TEST(join_bits, Seven)
{
    expect(0xffff0000);
    given(0,-1,15);
}


TEST(join_bits, Eight)
{
    expect(0xffff);
    given(-1,0,15);
}

