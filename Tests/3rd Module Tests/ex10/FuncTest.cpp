#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h>

#include <string.h>
  
 #include "asm.h"
 char * ptr1;
 char * ptr2; 
 char * ptr3; 
 
 void call_func(void (*f)());  
} 

//START: testGroup
TEST_GROUP(str_cat)
{
    char output[100];
    const char * expected;
    void setup()
    {
        memset(output, 0xaa, sizeof output);
        expected = "";
        ptr3=output;          // 
    }
    void teardown()
    {
    }
    void expect(const char * s)
    {
        expected = s;
	}
    void given(const char * str1, const char * str2)
    {
    	ptr1=(char*) str1; 	
    	ptr2=(char*) str2; 	
    	call_func(str_cat); 	
        STRCMP_EQUAL(expected, output);
        BYTES_EQUAL(0xaa, output[strlen(expected) + 1]);
    }
};
//END: testGroup


TEST(str_cat, Hey)
{
    expect("heyhey");
    given("hey","hey");
}

TEST(str_cat, Hello)
{
    expect("Hello World\n");
    given("Hello ","World\n");
}

TEST(str_cat, One_b)
{
    expect("One b");
    given("","One b");
}

TEST(str_cat, Two_b)
{
    expect("bb");
    given("b","b");
}


TEST(str_cat, Two_B)
{
    expect("Two BB");
    given("Two BB","");
}

TEST(str_cat, Null_String)
{
    expect("");
    given("","");
}





//END: RefactoredTests


