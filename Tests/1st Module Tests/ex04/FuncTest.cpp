#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h>

#include <string.h>
  
 #include "asm.h"
 char * ptr1;
 
} 

//START: testGroup
TEST_GROUP(upper1)
{
    char output[100];
    const char * expected;
    void setup()
    {
        memset(output, 0xaa, sizeof output);
        expected = "";
    }
    void teardown()
    {
    }
    void expect(const char * s)
    {
        expected = s;

	}
    void given(const char * str)
    { 
	strcpy(output,str); 
    	ptr1=output; 	
    	upper1(output); 	
        STRCMP_EQUAL(expected, output);
        BYTES_EQUAL(0xaa, output[strlen(expected) + 1]);
    }
};
//END: testGroup


TEST(upper1, Hex)
{
    expect("HEX");
    given("hex");
}

TEST(upper1, Abcd)
{
    expect("ABCD A");
    given("ABCD a");
}

TEST(upper1, Abba)
{
    expect(" ABBA ");
    given(" abba ");
}



TEST(upper1, OnlySpaces)
{
    expect("      ");
    given("      ");
}

TEST(upper1, Null_String)
{
    expect("");
    given("");
}





//END: RefactoredTests


