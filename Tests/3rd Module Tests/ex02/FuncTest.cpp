#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h>

#include <string.h>
  
 #include "asm.h"

void call_func( void (*f) ()); 

 char * ptr1;
 char * ptr2; 
 
} 

//START: testGroup
TEST_GROUP(str_copy_porto)
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
    	ptr1=(char*) str; 	
    	call_func(str_copy_porto); 	
        STRCMP_EQUAL(expected, output);
        BYTES_EQUAL(0xaa, output[strlen(expected) + 1]);
    }
};
//END: testGroup


TEST(str_copy_porto, Hey)
{
    expect("hey");
    given("hey");
}

TEST(str_copy_porto, Hello)
{
    expect("Hello World\n");
    given("Hello World\n");
}

TEST(str_copy_porto, One_b)
{
    expect("One b");
    given("One v");
}



TEST(str_copy_porto, Two_b)
{
    expect("Two bb");
    given("Two vv");
}


TEST(str_copy_porto, Two_B)
{
    expect("Two VBV" );
    given("Two VBV");
}


TEST(str_copy_porto, Two_v)
{
    expect("Two bB");
    given("Two bB");
}

TEST(str_copy_porto, Null_String)
{
    expect("");
    given("");
}





//END: RefactoredTests


