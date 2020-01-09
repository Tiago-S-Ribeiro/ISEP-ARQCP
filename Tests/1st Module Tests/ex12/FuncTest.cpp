#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h>

#include <string.h>
  
 #include "asm.h"
 
}

//START: testGroup
TEST_GROUP(capitalize)
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
        memcpy(output,str,strlen(str)+1); 		
    	capitalize(output); 	
        STRCMP_EQUAL(expected, output);
        BYTES_EQUAL(0xaa, output[strlen(expected) + 1]);
    }
};
//END: testGroup


TEST(capitalize, Hey)
{
    expect("Hey");
    given("hey");
}

TEST(capitalize, Hello)
{
    expect("Hello World\n");
    given("hello world\n");
}

TEST(capitalize, One_0)
{
    expect("One Zero 8");
    given("One zero 8");
}
TEST(capitalize, One_8)
{
    expect("One Eight E");
    given("One eight e");
}



TEST(capitalize, Two_0)
{
    expect("Two 2t");
    given("Two 2t");
}


TEST(capitalize, Case1)
{
    expect("The Number Must Be Saved ");
    given("The number must be saved ");
}


TEST(capitalize, Case2)
{
    expect("The Maximum Value Of This CYCLE");
    given("The maximum value of this CYCLE");
}

TEST(capitalize, Null_String)
{
    expect("");
    given("");
}


//END: RefactoredTests
