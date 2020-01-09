#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h>

#include <string.h>
  
 #include "asm.h"
 
}

//START: testGroup
TEST_GROUP(find_word)
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
    void given(const char * s1,const char *s2,char *p  )
    {  
	char * res;     
        memcpy(str1,s1,strlen(s1)+1); 		
        memcpy(str2,s2,strlen(s2)+1); 		
    	res=find_word(str2,str1,p); 	
        POINTERS_EQUAL(expected, res);
	STRCMP_EQUAL(s1,str1); 
	STRCMP_EQUAL(s2,str2); 
        BYTES_EQUAL(0xaa, str1[strlen(s1) + 1]);
        BYTES_EQUAL(0xaa, str2[strlen(s2) + 1]);
    }
};
//END: testGroup


TEST(find_word, Hey)
{
    expect(str2+2);
    given("x","rrxr X",str2);
}


TEST(find_word, Hey1)
{
    expect(str2+4);
    given("xrt","aarrxrt X",str2);
}


TEST(find_word, Hey2)
{
    expect(str2+8);
    given("xrt","aarrxrt xrt xrt xrt",str2+5);
}


TEST(find_word, Hey3)
{
    expect(str2+12);
    given("xrt","xaixrarrxrt xrt xrt xrt",str2+9);
}


TEST(find_word, Null_String1)
{
    expect(NULL);
    given("","",str2);
}

TEST(find_word, Null_String2)
{
    expect(NULL);
    given("","iwuoiuwe",str2);
}

TEST(find_word, Null_String3)
{
    expect(NULL);
    given("hdjshdhasdh","",str2);
}

TEST(find_word, Null_String4)
{
    expect(NULL);
    given("zz","zfzgzgzhzjzkzkzkz",str2);
}

TEST(find_word, Null_String5)
{
    expect(str2+8);
    given("zz","zfzgzgzhZZjzkzkzkz",str2);
}

//END: RefactoredTests
