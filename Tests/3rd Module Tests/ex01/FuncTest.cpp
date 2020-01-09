#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h> 
#include <string.h>  

#include "asm.h"   	

int call_func(int (*f)()); 
char * ptr1; 
}

//START: testGroup
TEST_GROUP(zero_count)
{
    char test_string[100];
    int  expected;
    void setup()
    {
        memset(test_string, 0xaa, sizeof test_string);
        expected = 0; 
	ptr1=test_string; 
    }
    void teardown()
    {
    }
    void expect(int num )
    {
        expected = num;
    }
    void given(const char s[])
    { 
	int result; 
	strncpy(test_string,s,strlen(s)+1);     	
	result=call_func(zero_count); 
        LONGS_EQUAL(expected, result);
        BYTES_EQUAL(0xaa, test_string[strlen(test_string) + 1]);
    }
};
//END: testGroup

TEST(zero_count, None)
{
    expect(0);
    given("hey");
}

TEST(zero_count, Hello)
{
    expect(1);
    given("Hello 0 World\n");
}


TEST(zero_count,Three_Zeros)
{
    expect(3);
    given("000");
}

TEST(zero_count, A_B_C_D)
{
    expect(3);
    given("A0B0C0D");
}

TEST(zero_count, OneZero)
{
    expect(1);
    given("0");
}

TEST(zero_count, Null)
{
    expect(0); 
    given("");
}

