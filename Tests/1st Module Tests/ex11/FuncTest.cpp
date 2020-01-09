#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h> 
#include <string.h> 
#include "asm.h"   	
}

//START: testGroup
TEST_GROUP(palindrome)
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
    void given(char * vec)
    { 
	int result; 
	 
	result=palindrome(vec); 
        LONGS_EQUAL(expected, result);
    }
};
//END: testGroup

TEST(palindrome, NullVector)
{
    expect(0); 
    given((char*)"");
}

TEST(palindrome, One)
{
    expect(1);
    given((char*)"v");
}


TEST(palindrome,Zero)
{
    expect(0);
    given((char*)"0000001");
}


TEST(palindrome,Case1)
{
    expect(1);
    given((char*)"Never odd or even");
}


TEST(palindrome,Case2)
{
    expect(1);
    given((char*)"A man a plan a canal Panama.");
}


TEST(palindrome,Case3)
{
    expect(1);
    given((char*)"Gateman sees name, garageman sees name tag");
}

