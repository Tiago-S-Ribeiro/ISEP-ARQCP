#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h>

#include <string.h>
  
 #include "asm.h"
 
}

//START: testGroup
TEST_GROUP(where_exists)
{
    char str1[100];
    char str2[100];
    char * expected;
    void setup()
    {
        memset(str1, 0xaa, sizeof str1);
        memset(str2, 0xaa, sizeof str2);
        expected = NULL; 

    }
    void teardown()
    {
    }
    void expect( char * s)
    {
        expected = s;
		

	}
    void given(const char * s1,const char *s2 )
    {  
	char * res;     
        memcpy(str1,s1,strlen(s1)+1); 		
        memcpy(str2,s2,strlen(s2)+1); 		
    	res=where_exists(str1,str2); 	
        POINTERS_EQUAL(expected, res);
	STRCMP_EQUAL(s1,str1); 
	STRCMP_EQUAL(s2,str2); 
        BYTES_EQUAL(0xaa, str1[strlen(s1) + 1]);
        BYTES_EQUAL(0xaa, str2[strlen(s2) + 1]);
    }
};
//END: testGroup


TEST(where_exists, Hey)
{
    expect(str2+2);
    given("x","rrxr X");
}


TEST(where_exists, Hey1)
{
    expect(str2+4);
    given("xrt","aarrxrt X");
}


TEST(where_exists, Hey2)
{
    expect(str2+4);
    given("xrt","aarrxrt xrt xrt xrt");
}


TEST(where_exists, Hey3)
{
    expect(str2+8);
    given("xrt","xaixrarrxrt xrt xrt xrt");
}


TEST(where_exists, Null_String1)
{
    expect(NULL);
    given("","");
}

TEST(where_exists, Null_String2)
{
    expect(NULL);
    given("","iwuoiuwe");
}

TEST(where_exists, Null_String3)
{
    expect(NULL);
    given("hdjshdhasdh","");
}

TEST(where_exists, Null_String4)
{
    expect(NULL);
    given("zz","zfzgzgzhzjzkzkzkz");
}

TEST(where_exists, Null_String5)
{
    expect(NULL);
    given("zz","zfzgzgzhZZjzkzkzkz");
}

//END: RefactoredTests
