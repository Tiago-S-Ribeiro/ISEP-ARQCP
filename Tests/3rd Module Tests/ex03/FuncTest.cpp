#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h>

#include <string.h>
  
 #include "asm.h"
 char * ptr1;
 char * ptr2; 
 
 void call_func(void (*f)()); 

}

//START: testGroup
TEST_GROUP(str_copy_porto2)
{
    char output[100];
    const char * expected;
    void setup()
    {
        memset(output, 0xaa, sizeof output);
        expected = "";
        ptr2=output;          // 
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
    	ptr1=(char *)str; 	
    	call_func(str_copy_porto2); 	
        STRCMP_EQUAL(expected, output);
        BYTES_EQUAL(0xaa, output[strlen(expected) + 1]);
    }
};
//END: testGroup


TEST(str_copy_porto2, Hey)
{
    expect("hey");
    given("hey");
}

TEST(str_copy_porto2, Hello)
{
    expect("Hello World\n");
    given("Hello World\n");
}

TEST(str_copy_porto2, One_v)
{
    expect("One b");
    given("One v");
}
TEST(str_copy_porto2, One_b)
{
    expect("One b");
    given("One b");
}



TEST(str_copy_porto2, Two_v)
{
    expect("Two bB");
    given("Two vV");
}


TEST(str_copy_porto2, Two_B)
{
    expect("Two BB");
    given("Two BB");
}


TEST(str_copy_porto2, Three_v)
{
    expect("Three bBb");
    given("Three vVv");
}

TEST(str_copy_porto2, Null_String)
{
    expect("");
    given("");
}


//END: RefactoredTests
