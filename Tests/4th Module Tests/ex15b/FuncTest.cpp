#include <CppUTest/TestHarness.h>

extern "C"
{
#include <stdio.h>
#include <memory.h> 
#include <string.h> 
#include "asm.h"   

int call_func(int (*f)(unsigned int, unsigned int ), int p_param, unsigned int , unsigned int ); 
}

unsigned int build_date( int year , int month , int day ) {

	return  (year << 8)  | (month <<24 ) |  day ;
}


//START: testGroup
TEST_GROUP(greater_date)
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
    void given(int x ,int y )
    { 
	int result; 
	result=call_func(greater_date,2,x,y); 
        LONGS_EQUAL(expected, result);
    }
};
//END: testGroup

TEST(greater_date, Zero)
{
    expect(build_date(2017,11,11));
    given(build_date(2017,11,11),build_date(2017,11,11));
}

TEST(greater_date, One)
{
    expect(build_date(2015,11,11));
    given(build_date(2015,11,10),build_date(2015,11,11));
}

TEST(greater_date, Two)
{
    expect(build_date(2015,11,11));
    given(build_date(2015,11,11),build_date(2015,11,10));
}

TEST(greater_date, Three)
{
    expect(build_date(2014,11,11));
    given(build_date(2014,10,11),build_date(2014,11,11));
}

TEST(greater_date, Four)
{
    expect(build_date(2014,11,11));
    given(build_date(2014,11,11),build_date(2014,10,11));
}

TEST(greater_date, Five)
{
    expect(build_date(2013,11,11));
    given(build_date(2012,11,11),build_date(2013,11,11));
}

TEST(greater_date, Six)
{
    expect(build_date(2013,11,11));
    given(build_date(2013,11,11),build_date(2012,11,11));
}


TEST(greater_date, Seven)
{
    expect(build_date(2013,11,11));
    given(build_date(2013,11,11),build_date(2,1,1));
}

TEST(greater_date, Eight)
{
    expect(build_date(2013,1,1));
    given(build_date(2013,1,1),build_date(12,12,31));
}

TEST(greater_date, Nine)
{
    expect(build_date(2013,1,31));
    given(build_date(2013,1,31),build_date(12,12,31));
}

TEST(greater_date, Ten)
{
    expect(build_date(10,11,11));
    given(build_date(10,11,11),build_date(2,12,31));
}

TEST(greater_date, Eleven)
{
    expect(build_date(256,1,1));
    given(build_date(256,1,1),build_date(255,12,31));
}
